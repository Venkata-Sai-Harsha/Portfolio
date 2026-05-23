import streamlit as st

# Define function to generate query (simulates API call)
def generate_query(text, schemas):
  """
  Simulates a call to a backend API for query generation
  """
  # Replace with actual API call logic if you have a backend
  # This is for demonstration purposes only
  if all(schema.strip() for schema in schemas):
    return f"Generated query based on text: '{text}' and schemas: {schemas}"
  else:
    return "Error: Please provide at least one non-empty schema."

# Streamlit app layout
st.title("SQL Query Generator")

# Text area for user input
inputText = st.text_area(
    "Enter your query in natural language...", key="user_input"
)

# Container for schema inputs
schema_container = st.container()

# List to store schema inputs
schemas = []

# Initially add one empty schema input
schemas.append("")

# Add a schema input section dynamically
for i in range(len(schemas)):
    schema_container.text_input(f"Enter schema {i + 1}", key=f"schema_{i}", value=schemas[i])

# Button to add more schema inputs
add_schema_button = st.button("Add Schema")

# Handle adding more schema input fields
if add_schema_button:
    schemas.append("")
    schema_container.empty()  # Clear container before adding new elements
    for i in range(len(schemas)):
        schema_container.text_input(f"Enter schema {i + 1}", key=f"schema_{i}", value=schemas[i])

# Button to generate query
generate_query_button = st.button("Generate SQL Query")

# Generate query and handle errors (simulated)
if generate_query_button:
    generated_query = generate_query(inputText, schemas)
    error = None
    if "Error" in generated_query:
        error = generated_query
    else:
        st.success("Generated SQL Query:")
    st.code(generated_query)
    if error:
        st.error(error)

