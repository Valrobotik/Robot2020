"""
@Autor = Cyril TESSIER & Nicolas LE FRANC
@But :
Pour l'association Valrobotik afin de gagner la coupe de France de robotique
"""

import numpy as np


class Camera(object):
    """docstring for Camera."""
    def __init__(self, distance_focale, nb_pixel, resolution, binningRatio = 1):
        super(Camera, self).__init__()
        self._position = np.array([0.0, 0.0, 0.0])      #position de X, Y, Z
        self._orientation = np.array([0.0, 0.0, 0.0])   #Orientation X, Y, Z
        self._nb_pixel = nb_pixel                       #Nombre de pixel en X,Y sous la forme (X,Y)
        self._centre_capteur = (resolution[0], resolution[1], distance_focale)  #Centre du capteur dans le repère de la caméra
        self._resolution = resolution                   #Resolution de la camera en (X,Y)
        self._binningRatio = binningRatio


    def position():
        doc = "The position property."
        def fget(self):
            return self._position
        def fset(self, value):
            self._position = np.array(value)
        def fdel(self):
            del self._position
        return locals()
    position = property(**position())

    def orientation():
        doc = "The orientation property."
        def fget(self):
            return self._orientation
        def fset(self, value):
            self._orientation = np.array(value)
        def fdel(self):
            del self._orientation
        return locals()
    orientation = property(**orientation())



    def generateHomogene(self, Points):
        """
        Permet de generer la matrice homogene de points 3D
        :param Points: Points de l'objet
        :return: Le vecteur colonne homogene (4x1)
        """
        Points_homogene = np.append(Points, [np.ones_like(Points[0])], axis=0)

        return Points_homogene


    def translation(self, Points, X = 0, Y = 0, Z = 0):
        """
        Permet de translater des points de l'espace 3D dans la direction X, Y, Z
        :param Points: Matrice HOMOGENE des points à translater.
        :param X: translation de TX suivant X
        :param Y: translation de TY suivant Y
        :param Z: translation de TZ suivant Z
        :return: La matrice homogene des points translatés
        """
        MatriceTranslation = np.array([[1, 0, 0, X],
                                       [0, 1, 0, Y],
                                       [0, 0, 1, Z],
                                       [0, 0, 0, 1] ])

        return np.dot(MatriceTranslation,Points)


    def miseEchelle(self, Points, ech=1):
        """
        Permet de redimentionner un vecteur dans un espace en 3D
        :param Points: Matrice HOMOGENE des points
        :param ech: facteur de mise à l'echelle
        :return: la matrice homogene mise à l'echelle
        """
        MatriceEchelle = np.array([[ech, 0, 0, 0],
                                   [0, ech, 0, 0],
                                   [0, 0, ech, 0],
                                   [0, 0,  0 , 1] ])

        return np.dot(MatriceEchelle, Points)



    def rotation(self, Points, alpha=0, beta=0, gamma=0 ):
        """
        Permet d'effectuer la rotation des points d'une image.
        @alpha : angle de rotation suivant X
        @beta  : angle de rotation suivant Y
        @gamme : angle de rotation suivant Z
        """

        Matrice_x = np.array([[1,       0      ,        0      , 0],
                              [0, np.cos(alpha), -np.sin(alpha), 0],
                              [0, np.sin(alpha), np.cos(alpha) , 0],
                              [0,      0       ,       0       , 1]])

        Matrice_y = np.array([[np.cos(beta) , 0, np.sin(beta), 0],
                              [0            , 1,       0     , 0],
                              [-np.sin(beta), 0, np.cos(beta), 0],
                              [0            , 0,        0    , 1]])

        Matrice_z = np.array([[np.cos(gamma), -np.sin(gamma), 0, 0],
                              [np.sin(gamma), np.cos(gamma) , 0, 0],
                              [     0       ,         0     , 1, 0],
                              [     0       ,         0     , 0, 1]])


        # Produit matriciel des différentes matrices de rotations
        matrice1 = np.dot(Matrice_x, Matrice_y)
        matrice2 = np.dot(matrice1, Matrice_z)

        return np.dot(matrice2, Points)


    def world2camera(self, Points):
        """
        Transformation de l'image suivant la position de la camera.
        """
        PointsRotate = self.rotation(Points, alpha = self._orientation[0],
                                     beta = self._orientation[1],
                                     gamma = self._orientation[2])

        PointsTranslation = self.translation(PointsRotate, X=self._position[0],
                                             Y=self._position[1],
                                             Z=self._position[2])

        return PointsTranslation

    def project(self, Points):
        """
        Permet de projeter des points 3D dans un espace 2D.
        Cela prend en compte la distance focale de la caméra.
        :param Points: matrice HOMOGENE des points dans l'espace 3D
        :return: matrice homogene des points dans l'espace 2D
        """
        f = 1/self._centre_capteur[2]
        px = self._position[0]/self._resolution[0]
        py = self._position[1]/self._resolution[1]

        MatriceProject = np.array([[f, 0, px, 0],
                                   [0, f, py, 0],
                                   [0, 0, 1, 0] ])

        mx = self._resolution[0]/self._binningRatio
        my = self._resolution[1]/self._binningRatio
        Meter2pixel = np.array(
            [[mx, 0 , 0],
             [ 0, my, 0],
             [ 0, 0 , 1] ])


        Matrice1 = np.dot(Meter2pixel, MatriceProject)
        PointsCamera = np.dot(Matrice1, Points)

        return np.stack((PointsCamera[0]/PointsCamera[2], PointsCamera[1]/PointsCamera[2]))

    def projectCamera(self, Points):
        """
        Fonction finale pour projeter des points de l'espace dans le repère de la camera.
        """
        PointCamera = self.world2camera(Points)
        PointProject = self.project(PointCamera)

        return PointProject










def main():
    import matplotlib.pyplot as plt
    import matplotlib.patches as patches
    from mpl_toolkits.mplot3d import Axes3D

    camera = Camera(3.04, 1000, (3280, 2464) )
    camera.position = [0., 0., 10]
    camera.orientation = [np.pi/6, 0., 0.]



    droite1 = [np.ones(10000, dtype=float) * 10, np.arange(0, 1000, 0.1), np.ones(10000, dtype=float) * 0]
    droite2 = [np.ones(10000, dtype=float) * -10, np.arange(0, 1000, 0.1), np.ones(10000, dtype=float) * 0]

    droiteproj1 = camera.projectCamera(camera.generateHomogene(droite1))
    droiteproj2 = camera.projectCamera(camera.generateHomogene(droite2))


    fig, axs = plt.subplots(1, 2, figsize=(12,6))

    axs[0].axis('equal')
    axs[0].plot(droite1[0], droite1[1])
    axs[0].plot(droite2[0], droite2[1])

    axs[1].axis('equal')
    axs[1].plot(droiteproj1[0], droiteproj1[1])
    axs[1].plot(droiteproj2[0], droiteproj2[1])
    axs[1].set_xlim([-camera._resolution[0]/2, camera._resolution[0]/2])
    axs[1].set_ylim([-camera._resolution[1]/2, camera._resolution[1]/2])
    axs[1].set_title("Position de la camera {} mm, angle {} rad".format(camera._position, np.round(camera._orientation,2)))

    rect = patches.Rectangle((-camera._resolution[0]/2, camera._resolution[1]/2), camera._resolution[0], -camera._resolution[1], alpha=1, fill=None)

    # Add the patch to the Axes
    axs[1].add_patch(rect)

    # fig2 = plt.figure()
    # ax = fig2.add_subplot(111, projection='3d')
    # ax.scatter(droiteproj1, droiteproj2, zs=droiteproj3)
    plt.show()





if __name__ == '__main__':
    main()
