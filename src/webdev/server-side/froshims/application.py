from flask import Flask, render_template, request, redirect
from flask_mail import Mail, Message
import sqlite3

app = Flask(__name__)


SPORTS = [
  "Dodgeball",
  "Flag Football",
  "Soccer",
  "Volleyball",
  "Ultimate Frisbee"
]

@app.route("/")
def index():
  return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
  name = request.form.get("name")
  sport = request.form.get("sport")

  if not name:
    return render_template("error.html", message="Missing name")
  if not sport:
    return render_template("error.html", message="Missing sport")
  if sport not in SPORTS:
    return render_template("error.html", message="Invalid sport")

  with sqlite3.connect("froshims.db") as conn:
    cur = conn.cursor()
    cur.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", (name, sport))
    conn.commit()
  return redirect("/registrants")


@app.route("/registrants")
def registrants():
  with sqlite3.connect("froshims.db") as conn:
    conn.row_factory = sqlite3.Row    # sqlite3.Row provides both index-based and name-based access
    cur = conn.cursor()
    registrants = cur.execute("SELECT * FROM registrants").fetchall()
  
  return render_template("registrants.html", registrants=registrants)

