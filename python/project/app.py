import streamlit as st

st.title("My First Streamlit Frontend")

name = st.text_input("Enter your name:")
if st.button("Say hello"):
    st.write(f"Hello, {name}!")