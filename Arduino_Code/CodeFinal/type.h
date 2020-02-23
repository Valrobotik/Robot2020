//Strucutre pour les paramètres moteurs.
typedef struct motorParam motorParam;
 struct motorParam{
    int StepPin;
    int DirectionPin;
    int EnablePin;
} ;

//Structure pour les coordonnées.
typedef struct Point Point;
struct Point {
    float x;
    float y;
};
