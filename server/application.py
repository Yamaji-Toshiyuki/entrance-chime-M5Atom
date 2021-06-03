from flask import Flask
import subprocess as sp
from playsound import playsound as ps
import datetime
import threading
import sqlite3

app = Flask(__name__)
db_name = "/home/haruyuki/Documents/Entrance_chime_M5Atom/server/chime_pushed_timestamp.db"
cnt = 0

def play():
    ps("/home/haruyuki/Documents/Entrance_chime_M5Atom/server/chime_sound.mp3")

def log():
    now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    cnxn = sqlite3.connect(db_name)
    cur = cnxn.cursor()
    print("INSERT INTO timestamp(timestamp) values('" + now + "')")
    cur.execute("INSERT INTO timestamp(timestamp) values('" + now + "')")
    cnxn.commit()
    cur.close()
    cnxn.close()


@app.route("/")
def index():
    return "hello"

@app.route("/M5ButtonPushed")
def m5ButtonPushed():
    global cnt
    cnt += 1
    psthread = threading.Thread(target=play)
    psthread.start()
    sp.Popen(["notify-send", "someone comes to home"])
    log()
    return "success"

if __name__ == "__main__":
    app.run(debug=True, port=16278, host="0.0.0.0")