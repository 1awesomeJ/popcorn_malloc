#import openai_secret_manager
import requests
import json
import openai
import os


# Set the OpenAI API key
api_key = os.environ["OPENAI_API_KEY"]
openai.api_key = api_key

# Set the URL for the DALL-E API endpoint
url = "https://api.openai.com/v1/images/generations"

# Set the prompt and model name
prompt = input("Enter your prompt for DALL-E2\n")
model = "image-alpha-001"

# Set the request headers
headers = {
    "Content-Type": "application/json",
    "Authorization": f"Bearer {api_key}"
}

# Set the request data
data = {
    "model": model,
    "prompt": prompt,
    "num_images": 1,
    "size": "1024x1024",
    "response_format": "url"
}

# Send the request to the DALL-E API endpoint
response = requests.post(url, headers=headers, json=data)

# Check the response status code
if response.status_code != 200:
    raise ValueError(f"Request failed with status code {response.status_code}")

# Extract the URL of the generated image from the response
response_data = response.json().get("data", [])
if not response_data:
    raise ValueError("Response data is empty")
image_url = response_data[0].get("url")
print ("The generated image is at {}".format(image_url))
if not image_url:
    raise ValueError("Image URL is missing")

# Display the generated image
#from IPython.display import Image
#Image(url=image_url)









