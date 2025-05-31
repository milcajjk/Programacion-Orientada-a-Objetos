#include <iostream>
#include <string>

using namespace std;

class Animal
 { 
protected:
    string color;
    bool tieneCola;
    bool tiene4Patas;  
    string tipoAlimentacion;
    
public:
    Animal(string c, bool cola, bool patas, string alimentacion) {
        color = c;
        tieneCola = cola;
        tiene4Patas = patas;  
        tipoAlimentacion = alimentacion;
    }
    
    void mostrarDatos() {
        cout << "Color: " << color << endl;
        cout << "Tiene cola: " << (tieneCola ? "Si" : "No") << endl;
        cout << "Tiene 4 patas: " << (tiene4Patas ? "Si" : "No") << endl; 
        cout << "Tipo de alimentacion: " << tipoAlimentacion << endl; 
    }
};

class Insecto : public Animal {
public:
    Insecto(string c, bool cola, string alimentacion)
        : Animal(c, cola, false, alimentacion) {}
};

class Mamifero : public Animal {
public:
    Mamifero(string c, bool cola, string alimentacion)
        : Animal(c, cola, true, alimentacion) {}
};

class Pajaro : public Animal {
public:
    Pajaro(string c, bool cola, string alimentacion)
        : Animal(c, cola, false, alimentacion) {}
};

int main() {
    Mamifero perro("Marron", true, "Omnivoro");
    Insecto abeja("Amarillo y negro", true, "Herbivoro");
    Pajaro loro("Verde", true, "Herbivoro");
    
    cout << "--- Perro ---" << endl;
    perro.mostrarDatos();
    
    
    cout << "\n --- Abeja ---" << endl;
    abeja.mostrarDatos();
   
    
    cout << "\n --- Loro ---" << endl;
    loro.mostrarDatos();
   
    
    return 0;
}

