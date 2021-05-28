from flask import Flask
import subprocess as sp

app = Flask(__name__)
cnt = 0

@app.route("/")
def index():
    return "hello"

@app.route("/M5ButtonPushed")
def m5ButtonPushed():
    global cnt
    cnt += 1
    sp.Popen(["notify-send", str(cnt)])
    return "success"

if __name__ == "__main__":
    app.run(debug=True, port=16278, host="0.0.0.0")