#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    this->shape=RectangleShape(size);
    this->speed=Vector2f(0.f,0.f);
    this->objective=Vector2f(0.f,0.f);
    this->shape.setFillColor(Color::Red);
}

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    this->shape=RectangleShape(size);
    this->speed=Vector2f(0.f,0.f);
    this->objective=Vector2f(0.f,0.f);
    this->shape.setFillColor(Color::Red);
    this->shape.setPosition(Vector2f(position));
}

void Rectangle::update()
{
   this->shape.move(speed);
    if(shape.getPosition().x-Mouse::getPosition().x<=5 && shape.getPosition().y-Mouse::getPosition().y <=5){
        shape.setPosition(shape.getPosition());
        this->shape.setFillColor(Color::Green);
    }
    /**(6pts)
        Mueve el cuadrado.
        Si el cuadrado está a menos de 5 pixeles del objetivo, detén el cuadrado y píntalo de verde.
        Si no, píntalo de rojo.
            - Puedes saber si está a 5 pixeles del objetivo si la diferencia entre la coordeanda x del cuadrado y la x del objetivo es menor a 5 y lo mismo con la y.
    */
}

void Rectangle::setObjective(Vector2f objective)
{   
    this->objective.x=Mouse::getPosition().x;
    this->objective.y=Mouse::getPosition().y;
    float a,b,c;
    a=objective.x;
    b=objective.y;
    a=a*a;
    b=b*b;
    c=sqrt(a+b);
    
    float direccionx=shape.getPosition().x;
    float direcciony=shape.getPosition().y;
    Vector2f direcciontot(direccionx-objective.x, direcciony-objective.y);
    float magnitudx=shape.getPosition().x-c;
    float magnitudy=shape.getPosition().y-c;
    Vector2f magnitudtot(magnitudx-objective.x, magnitudy-objective.y);
    Vector2f velocidad(direccionx-objective.x/magnitudx-objective.x,direcciony-objective.y/magnitudy-objective.y);
    this->speed=magnitudtot;
    /**Reto de valientes (0.5 décimas extra)
        Haz que el centro del cuadrado se posicione donde se dio click en lugar de que la esquina superior izquierda se posicione donde se dio click.
    */
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
