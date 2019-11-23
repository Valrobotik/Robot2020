import serial

"""
!!!!!!! A changer avec le port de l'arduino sur la rasperry !!!!!!!
Pour trouver le port :

- Avec l'arduino débranchée
ls /dev/tty*

- Avec l'arduino branchée
ls /dev/tty*

- On recherche le nouveau port connecté ;)
"""
ser = serial.Serial('/dev/ttyACM0', 9600)

print("CTRL + C pour arrêter")

while True :
	gcode = str(input('Entrer le Gcode\n')) #Commande pour tester à la main
	msg = gcode.encode()    #Transformation en bytes pour Serial
	ser.write(msg)