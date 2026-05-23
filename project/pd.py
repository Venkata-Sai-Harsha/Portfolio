import streamlit as st
import torch
from transformers import GPT2Tokenizer, GPT2ForSequenceClassification

# Load model and tokenizer
@st.cache_resource
def load_model():
    model_name = "H1tak3/phishing-url-detector"
    tokenizer = GPT2Tokenizer.from_pretrained(model_name)
    model = GPT2ForSequenceClassification.from_pretrained(model_name)
    return tokenizer, model

# Set up Streamlit page configuration
st.set_page_config(
    page_title="Phishing URL Detector",
    layout="centered",
    initial_sidebar_state="collapsed",
)

# Custom CSS for black background and white text
st.markdown(
    """
    <style>
        body {
            background-color: black;
            color: white;
        }
        .url-checker {
            padding: 20px;
            border: 2px solid white;
            border-radius: 10px;
            background-color: #1e1e1e;
            color: white;
        }
        .stButton button {
            background-color: white;
            color: black;
            border: none;
            padding: 10px;
            border-radius: 5px;
        }
        .stButton button:hover {
            background-color: #d3d3d3;
        }
    </style>
    """,
    unsafe_allow_html=True,
)

# Title and description
st.title("🔍 Phishing URL Detector")
st.markdown(
    "Detect whether a given URL is **phishing** or not"
)

# Load tokenizer and model
tokenizer, model = load_model()


url = st.text_input("Enter the URL to check:")

# Prediction logic
if st.button("Check URL"):
    if url:
        inputs = tokenizer(url, return_tensors="pt", truncation=True, max_length=512)
        with torch.no_grad():
            outputs = model(**inputs)
            logits = outputs.logits
            prediction = torch.argmax(logits, dim=1).item()

        result = "Phishing" if prediction == 1 else "Legitimate"
        st.markdown(f"### The URL is **{result}**.")
    else:
        st.error("Please enter a URL.")

st.markdown('</div>', unsafe_allow_html=True)





