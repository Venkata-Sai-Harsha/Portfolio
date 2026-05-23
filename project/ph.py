import streamlit as st
import pandas as pd
import numpy as np
import pickle
import re
import requests
import tldextract
from urllib.parse import urlparse
from sklearn.preprocessing import StandardScaler
import hashlib
from tld import get_tld
import plotly.express as px

# Function definitions for feature extraction and utility functions
def hash_url_to_number(url):
    hashed_value = int(hashlib.md5(url.encode()).hexdigest(), 16)
    return hashed_value

def has_suspicious_patterns(url):
    suspicious_keywords = ['login', 'signin', 'bank', 'secure', 'account', 'update', 'confirm', 'verify']
    return 1 if any(keyword in url.lower() for keyword in suspicious_keywords) else 0

def get_full_domain(url):
    extracted = tldextract.extract(url)
    full_domain = f"{extracted.subdomain}.{extracted.domain}.{extracted.suffix}" if extracted.subdomain else f"{extracted.domain}.{extracted.suffix}"
    return full_domain

def primary_domain_length(url):
    extracted = tldextract.extract(url)
    primary_domain = f"{extracted.domain}.{extracted.suffix}"
    return len(primary_domain)

def fd_length(url):
    url_path = urlparse(url).path
    try:
        return len(url_path.split("/")[1])
    except IndexError:
        return 0

def get_tld_length(url):
    try:
        tld = get_tld(url, fail_silently=True)
        return len(tld) if tld else 0
    except Exception:
        return 0

def subdomain_count(url):
    extracted = tldextract.extract(url)
    subdomains = extracted.subdomain.split('.')
    return len(subdomains) if extracted.subdomain else 0

def extract_features_from_url(url):
    parsed_url = urlparse(url)
    features = []

    features.append(hash_url_to_number(url))
    features.append(1 if re.search(r'\d+\.\d+\.\d+\.\d+', url) else 0)
    features.append(1 if '@' in url else 0)
    features.append(1 if 'google.com' in url else 0)
    features.append(url.count('.'))
    features.append(url.count('www'))
    features.append(url.count('@'))
    features.append(url.count('/'))
    features.append(url.count('embed'))
    features.append(1 if len(url) < 54 else 0)
    features.append(url.count('https'))
    features.append(url.count('http'))
    features.append(url.count('%'))
    features.append(url.count('?'))
    features.append(url.count('-'))
    features.append(url.count('='))
    features.append(len(url))
    features.append(primary_domain_length(url))
    features.append(1 if 'suspect' in url else 0)
    features.append(sum(c.isdigit() for c in url))
    features.append(sum(c.isalpha() for c in url))
    features.append(fd_length(url))
    features.append(get_tld_length(url))
    features.append(has_suspicious_patterns(url))
    features.append(subdomain_count(url))

    ip_address = re.search(r'\d+\.\d+\.\d+\.\d+', url)
    features.append(1 if ip_address else 0)

    features.append(len(parsed_url.netloc))
    features.extend([0, 0, 0, 0])  # ISP_Rank, TLD_Rank, Country_Rank, Region_Rank placeholders

    return np.array(features).reshape(1, -1)

def load_model_from_upload():
    model = None
    scaler = None
    
    st.sidebar.header("Model Files Upload")
    
    model_file = st.sidebar.file_uploader("Upload Model File (rf_model_without_smote.pkl)", type=['pkl'])
    scaler_file = st.sidebar.file_uploader("Upload Scaler File (scaler.pkl)", type=['pkl'])
    
    if model_file and scaler_file:
        try:
            model = pickle.load(model_file)
            scaler = pickle.load(scaler_file)
            st.sidebar.success("✅ Model and scaler loaded successfully!")
        except Exception as e:
            st.sidebar.error(f"Error loading model files: {str(e)}")
    
    return model, scaler

# Streamlit UI
def main():
    st.title("URL Phishing Detection App")
    st.write("Enter a URL to check if it's potentially a phishing site")

    # Load model and scaler through file upload
    model, scaler = load_model_from_upload()

    # URL input
    url = st.text_input("Enter URL:", "https://www.example.com")

    if st.button("Check URL"):
        if model is None or scaler is None:
            st.warning("⚠️ Please upload both the model and scaler files first!")
            return

        try:
            # Extract features
            url_features = extract_features_from_url(url)

            # Scale features
            url_features_scaled = scaler.transform(url_features)

            # Make prediction
            prediction = model.predict(url_features_scaled)

            # Display the prediction result
            col1, col2 = st.columns([1, 2])
            with col1:
                if prediction[0] == 1:
                    st.error("⚠️ Warning!")
                else:
                    st.success("✅ Safe")

            with col2:
                if prediction[0] == 1:
                    st.write("This URL is potentially a phishing site!")
                else:
                    st.write("This URL appears to be legitimate.")

            # Display feature details in an expander
            with st.expander("View Detailed Analysis"):
                feature_names = [
                    "URL Hash", "Use of IP", "Abnormal URL", "Google Index", "Dot Count", 
                    "WWW Count", "@ Count", "Directory Count", "Embed Domain Count", 
                    "Short URL", "HTTPS Count", "HTTP Count", "% Count", "? Count", 
                    "Hyphen Count", "Equal Count", "URL Length", "Primary Domain Length",
                    "Suspicious URL", "Digit Count", "Letter Count", "First Directory Length",
                    "TLD Length", "Suspicious Patterns", "Subdomain Count", "Has IP Address",
                    "Hostname Length", "ISP Rank", "TLD Rank", "Country Rank", "Region Rank"
                ]

                features_df = pd.DataFrame({
                    'Feature': feature_names,
                    'Value': url_features[0]
                })

                st.dataframe(features_df, use_container_width=True)

            # Add visualization of key features
            with st.expander("Feature Visualization"):
                key_features = ['URL Length', 'Dot Count', 'Directory Count', 'Suspicious Patterns']
                key_values = [url_features[0][i] for i, name in enumerate(feature_names) if name in key_features]
                
                fig = px.bar(
                    x=key_features,
                    y=key_values,
                    title="Key Feature Values",
                    labels={'x': 'Feature', 'y': 'Value'}
                )
                st.plotly_chart(fig)

        except Exception as e:
            st.error(f"An error occurred while analyzing the URL: {str(e)}")
            st.write("Please check the URL format and try again.")

    # Information about the app
    with st.expander("About this app"):
        st.markdown("""
        ### How it works
        This app uses machine learning to analyze URLs and detect potential phishing websites. 
        It extracts various features from the URL and uses a trained Random Forest model to make predictions.
        
        ### Features analyzed:
        - URL structure and length
        - Presence of suspicious patterns
        - Domain characteristics
        - Special character usage
        - And many more...
        
        ### How to use:
        1. Upload the model and scaler files using the sidebar.
        2. Enter a URL in the input field.
        3. Click "Check URL" to analyze.
        4. View the detailed analysis in the expandable sections.
        """)

if __name__ == '__main__':
    main()