import time
from arduino.app_utils import App, Bridge

SEQUENCE = [0, 1, 0, 2]   # E, D, E, N
SHOW_SECONDS = 1.0
CYCLE_SECONDS = 10.0
VERSION = "v1"


def show(index):
    try:
        Bridge.call("show", index)
    except Exception as exc:
        print(f"Bridge indisponible : {exc}")


def loop():
    start = time.monotonic()
    print(f"EDEN {VERSION}")
    for index in SEQUENCE:
        show(index)
        time.sleep(SHOW_SECONDS)
    show(-1)
    reste = CYCLE_SECONDS - (time.monotonic() - start)
    if reste > 0:
        time.sleep(reste)


App.run(user_loop=loop)
