# EDEN – test Arduino UNO Q

Toutes les 10 secondes, la matrice LED 8×13 affiche E, D, E, N (1 s par lettre).

- `python/main.py` : boucle côté Linux (appelle le sketch via le Bridge)
- `sketch/sketch.ino` : dessine les lettres sur la matrice (côté MCU)
- `app.yaml` : métadonnées de l'app Arduino App Lab

## Déploiement sur la carte

```bash
cd ~/ArduinoApps
git clone https://github.com/Michallet/Test_LED_Arduino.git eden
arduino-app-cli app start ~/ArduinoApps/eden
arduino-app-cli app logs ~/ArduinoApps/eden
```

Mise à jour : `git pull` puis `arduino-app-cli app restart ~/ArduinoApps/eden`.
Pour tester le redéploiement, changer `VERSION` dans `python/main.py`.
