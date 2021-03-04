from flask import Flask, render_template, request, redirect, session
from flask_session import Session
import sqlite3


app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
  with sqlite3.connect("books.db") as conn:
    conn.row_factory = sqlite3.Row
    cur = conn.cursor()
    books = cur.execute("SELECT * FROM books").fetchall()
  return render_template("books.html", books=books)



@app.route("/cart", methods=["GET", "POST"])
def cart():
  if "cart" not in session:
    session["cart"] = []

  if request.method == "POST":
    id = request.form.get("id")
    if id:
      session["cart"].append(id)
    return redirect("/cart")
  
  with sqlite3.connect("books.db") as conn:
    conn.row_factory = sqlite3.Row
    cur = conn.cursor()
    query = "SELECT * FROM books WHERE id IN ({seq})".format(seq=','.join(['?']*len(session["cart"])))
    books = cur.execute(query, session["cart"]).fetchall()

  return render_template("cart.html", books=books)


@app.route("/delete", methods=["POST"])
def delete():
  id = request.form.get("id")
  session["cart"] = list(filter(lambda a: a!=id, session["cart"]))
  return redirect("/cart")


@app.route("/empty")
def empty():
  session["cart"].clear()
  return redirect("/cart")
