from flask import Flask, render_template, request

app = Flask(__name__)   # Turns current file into an application

# Specifying URL path/route
@app.route("/")   # `@` is a specialy Python declarator

def index():
  # Render HTML template
  # Use the `request` library to parse URL input "name" and store in variable `name`
  # Set "world" as default value for `name`
  return render_template("index.html")


# Point to alternate URL path
@app.route("/greet", methods=['POST'])
def greet():
  return render_template("greet.html", name=request.form.get("name", "world"))