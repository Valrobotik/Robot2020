import serial
import time

"""
!!!!!!! A changer avec le port de l'arduino sur la rasperry !!!!!!!
Pour trouver le port :

- Avec l'arduino débranchée
ls /dev/tty*

- Avec l'arduino branchée
ls /dev/tty*

- On recherche le nouveau port connecté ;)
"""
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=0)

print("CTRL + C pour arrêter")

while True :
	# gcode = str(input('Entrer le Gcode\n')) #Commande pour tester à la main
	# msg = gcode.encode()    #Transformation en bytes pour Serial
	# ser.write(msg)
	print("Alume\a")
	msg = "L0".encode()
	ser.write(msg)
	time.sleep(3)

	print("Eteind\a")
	msg = "L1".encode()
	ser.write(msg)
	time.sleep(3)
