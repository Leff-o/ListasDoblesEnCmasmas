#include <iostream>

#include "Book.h"
#include "LinkedDouble.cpp"
    using namespace std;
    bool seguir = true;
    int main() {
        int opcion;
        LinkedDouble <Book> *linked = new LinkedDouble<Book>();
        linked->addNodeLast(Book("8374", "ajsfisaosnf", "ianfjanfoiaf", 12, 10));
        linked->addNodeLast(Book("234", "ajsfisaosnf", "ianfjanfoiaf", 12, 10));
        linked->addNodeLast(Book("123", "ajsfisaosnf", "ianfjanfoiaf", 12, 10));
        linked->addNodeLast(Book("000", "ajsfisaosnf", "ianfjanfoiaf", 12, 10));

       // cout<<(*linked->getObject(1));



      do{ cout << "\n|-------------------|";
        cout << "\n| 1. Crear Libro    | ";
        cout << "\n| 2. Buscar Libro   | ";
        cout << "\n| 3. Eliminar Libro | ";
        cout << "\n| 4. Mostrar Libros | ";
        cout << "\n| 5. Salir           | ";
        cout << "\n|-------------------|";
        cout << "\n\n Escoja una Opcion: \n";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string ISBN;
                string titulo;
                string autor;
                int paginas;
                int year;
                cout << "\n\n CREAR UN NUEVO LIBRO \n\n";

                cout << "\n\n INSERTE ISBN\n";
                cin >> ISBN;

                cout << "\n\n INSERTE TITULO\n";
                cin >> titulo;
                cout << "\n\n INSERTE AUTOR\n";
                cin >> autor;
                cout << "\n\n INSERTE PAGINAS\n";
                cin >> paginas;
                cout << "\n\n INSERTE AÑO\n";
                cin >> year;

                Book *book = new Book(ISBN, titulo, autor, paginas, year);
                //linked->addNodeFirst(*book);
                int optInt;
                cout << "Ingrese el número para agregar el Libro en la posición deseada\n";
                cout << "1. Al principio\n2. Al final\n3.Antes de\n4.Después de\n";
                cin >> optInt;
                switch (optInt) {
                    case 1:
                        linked->addNodeFirst(*book);
                        break;
                    case 2:
                        linked->addNodeLast(*book);
                        break;

                    case 3: {
                        string information;
                        cout << "Ingrese el ISBN del libro referencia\n";
                        cin >> information;

                        Node<Book> *findBook = linked->findNode(information);
                        linked->addNodeBeforeTo(findBook, *book);
                    }
                        break;

                    case 4:
                        string information;
                        cout << "Ingrese el ISBN del libro referencia\n";
                        cin >> information;

                        Node<Book> *findBook = linked->findNode(information);
                        linked->addNodeAfterTo(findBook, *book);

                        break;
                }

            }
                break;
            case 2: {
                string ISBN;
                cout << "Ingrese el ISBN del libro\n";
                cin >> ISBN;
                Book *findBook = linked->findInfo(ISBN);

                if (findBook != NULL) {
                    cout << "encontrado\n";
                    cout << *findBook << endl;
                } else {
                    cout << "Nel" << endl;
                }
            }
                break;

            case 3:{
                string ISBN;
                cout << "Ingrese el ISBN del libro\n";
                cin >> ISBN;
                Node <Book> *findNode = linked->findNode(ISBN);
                linked->deleteNode(findNode);

            }
                break;

            case 4:

                for (Book book : linked->getList( true ) ){
                   cout<<book<<endl;
                }
                break;

            case 5: {
                cout<<"BYE BYE"<<endl;
               seguir = false;
            }
                break;

        }
          }while(seguir);
        return 0;

    }
