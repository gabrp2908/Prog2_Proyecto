#include "controller/controller.h"
#include "view/view.h"
#include "model/model.h"

int main(){
    cout << "MENU INICIO DE SESION" << endl;
    
    string username, password;

    cout << "Ingrese su nombre de usuario: ";
    cin >> username;
    cout << "Ingrese su clave: ";
    cin >> password;    

    Usuario usuarioAutenticado = Login(username, password);
    MenuPorRol(usuarioAutenticado);

    return 0;
}
