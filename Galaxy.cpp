#include <graphics.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <dos.h>

using namespace std;

void hablar(const string& frase) {
    string comando = "espeak -ves-la+m1 \"" + frase + "\"";  // f3 para voz femenina en español
    const char* audio = comando.c_str();
    system(audio);
}

void dibujarMenu() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(200, 50, "Galaxy - Menu principal");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "1. Navegacion Web");
    outtextxy(200, 200, "2. Abrir Programa");
    outtextxy(200, 250, "3. Navegacion de Musica");
    outtextxy(200, 300, "4. Redes Sociales");
    outtextxy(200, 350, "5. Salir");
}

// Función para detectar clics en el menú
int detectarOpcion(int x, int y) {
    if (x >= 200 && x <= 600) {
        if (y >= 150 && y <= 180) return 1;
        if (y >= 200 && y <= 230) return 2;
        if (y >= 250 && y <= 280) return 3;
        if (y >= 300 && y <= 330) return 4;
        if (y >= 350 && y <= 380) return 5;
    }
    return 0;
}

void realizarBusquedaEnGoogle() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Google?");
    string frase = "Que deseas buscar en Google?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://www.google.com/search?q=" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '+'; // Reemplazar espacios con '+'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}

// Función para visitar YouTube
void realizarBusquedaEnYoutube() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Youtube?");
    string frase = "Que deseas buscar en Youtube?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://www.youtube.com/results?search_query=" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '+'; // Reemplazar espacios con '+'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}

// Función para buscar en Wikipedia
void realizarBusquedaEnWikipedia() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Wikipedia?");
    string frase = "Que deseas buscar en Wikipedia?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://es.wikipedia.org/wiki/" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '_'; // Reemplazar espacios con '_'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}
// Simulación de funcionalidades
void subMenuNavegacionWeb() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(200, 50, "Navegacion Web");

        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(200, 150, "1. Buscar en Google");
        outtextxy(200, 200, "2. Buscar en YouTube");
        outtextxy(200, 250, "3. Buscar en Wikipedia");
        outtextxy(200, 300, "4. Volver al Menu Principal");

        int x, y;
        while (!ismouseclick(WM_LBUTTONDOWN)) delay(50);
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if (x >= 200 && x <= 600) {
            if (y >= 150 && y <= 180) {
                realizarBusquedaEnGoogle();
            } else if (y >= 200 && y <= 230) {
            	realizarBusquedaEnYoutube();
            } else if (y >= 250 && y <= 280) {
            	realizarBusquedaEnWikipedia();
            } else if (y >= 300 && y <= 330) {
                // Volver al menú principal
                return;
            }
        }
    }
}

void abrirPrograma() {
    cleardevice();  // Limpiar la pantalla
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 50, "Ingrese el nombre o ruta del programa:");
    string frase = "Ingrese el nombre o ruta del programa que deseas abrir";
    hablar(frase);

    char nombrePrograma[100];
    setcolor(GREEN);
    rectangle(200, 100, 600, 140);  // Cuadro de entrada
    moveto(210, 110);

    // Capturar texto del usuario (nombre o ruta del programa)
    int i = 0;
    while (true) {
        char c = getch();  // Capturar un carácter
        if (c == 13) {  // Si se presiona Enter
            nombrePrograma[i] = '\0';  // Terminar la cadena
            break;
        } else if (c == 8 && i > 0) {  // Si se presiona retroceso
            i--;
            nombrePrograma[i] = '\0';
            outtextxy(210, 110, nombrePrograma);
        } else if (i < 99) {  // Si la cadena no es mayor que 100 caracteres
            nombrePrograma[i++] = c;
            nombrePrograma[i] = '\0';
            outtextxy(210, 110, nombrePrograma);
        }
    }

    // Intentar abrir el programa usando el comando "system"
    string comando = string(nombrePrograma);
    if (system(comando.c_str()) != 0) {
        outtextxy(200, 200, "Error al intentar abrir el programa.");
        string frase = "Error al intentar abrir el programa.";
    	hablar(frase);
    } else {
        outtextxy(200, 200, "Programa abierto exitosamente.");
        string frase = "Programa abierto exitosamente";
    	hablar(frase);
    }

    delay(2000);  // Mostrar mensaje por 2 segundos
}



void realizarBusquedaEnSpotify() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Spotify?");
    string frase = "Que deseas buscar en Spotify?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://open.spotify.com/search/" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '%'; // Reemplazar espacios con '%20'
            url.insert(i + 1, "20"); // Reemplazar espacios con '%20'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}

void realizarBusquedaEnAppleMusic() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Apple Music?");
    string frase = "Que deseas buscar en Apple Music?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://music.apple.com/search?term=" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '%'; // Reemplazar espacios con '%20'
            url.insert(i + 1, "2B"); // Reemplazar espacios con '%2B'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}

void realizarBusquedaEnYoutubeMusic() {
    cleardevice();
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Que deseas buscar en Youtube Music?");
    string frase = "Que deseas buscar en Youtube Music?";
    hablar(frase);

    char terminoBusqueda[100];
    setcolor(GREEN);
    rectangle(200, 200, 600, 240); // Cuadro de entrada
    moveto(210, 210);

    // Capturar texto del usuario
    int i = 0;
    while (true) {
        char c = getch();
        if (c == 13) { // Enter
            terminoBusqueda[i] = '\0';
            break;
        } else if (c == 8 && i > 0) { // Retroceso
            i--;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        } else if (i < 99) {
            terminoBusqueda[i++] = c;
            terminoBusqueda[i] = '\0';
            outtextxy(210, 210, terminoBusqueda);
        }
    }

    string terminoBusquedaStr(terminoBusqueda);

    // Construir la URL de búsqueda de Google
    string url = "https://music.youtube.com/search?q=" + terminoBusquedaStr;
    for (size_t i = 0; i < url.length(); ++i) {
        if (url[i] == ' ') {
            url[i] = '+'; // Reemplazar espacios con '+'
        }
    }

    // Usar el comando "start" para abrir la URL en el navegador predeterminado
    if (system(("start " + url).c_str()) != 0) {
        cerr << "Error al abrir la URL en el navegador predeterminado.\n";
    }
}

void subMenuBuscadorMusica() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(200, 50, "Navegacion de Musica");
        string frase = "Seleccion en cual plataforma quieres realizar la busqueda";
    	hablar(frase);

        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(200, 150, "1. Buscar en Spotify");
        outtextxy(200, 200, "2. Buscar en Apple Music");
        outtextxy(200, 250, "3. Buscar en Youtube Music");
        outtextxy(200, 300, "4. Volver al Menu Principal");

        int x, y;
        while (!ismouseclick(WM_LBUTTONDOWN)) delay(50);
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if (x >= 200 && x <= 600) {
            if (y >= 150 && y <= 180) {
                realizarBusquedaEnSpotify();
            } else if (y >= 200 && y <= 230) {
            	realizarBusquedaEnAppleMusic();
            } else if (y >= 250 && y <= 280) {
            	realizarBusquedaEnYoutubeMusic();
            } else if (y >= 300 && y <= 330) {
                // Volver al menú principal
                return;
            }
        }
    }
}

void subMenuRedSocial() {
    while (true) {
        cleardevice();
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(200, 50, "Redes Sociales");

        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(200, 150, "1. Facebook");
        outtextxy(200, 200, "2. X/Twitter");
        outtextxy(200, 250, "3. Instagram");
        outtextxy(200, 300, "4. LinkedIn");
        outtextxy(200, 350, "5. Volver al Menu Principal");
        string frase = "Selecciona la red social que quieras abrir";
    	hablar(frase);

        int x, y;
        while (!ismouseclick(WM_LBUTTONDOWN)) delay(50);
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if (x >= 200 && x <= 600) {
            std::string url;

            if (y >= 150 && y <= 180) {
                url = "https://www.facebook.com";
                string frase = "Abriendo Facebook";
    			hablar(frase);
            } else if (y >= 200 && y <= 230) {
                url = "https://www.x.com";
                string frase = "Abriendo X";
    			hablar(frase);
            } else if (y >= 250 && y <= 280) {
                url = "https://www.instagram.com";
                string frase = "Abriendo instagram";
    			hablar(frase);
            } else if (y >= 300 && y <= 330) {
                url = "https://www.linkedin.com";
                string frase = "Abriendo linkedin";
    			hablar(frase);
            } else if (y >= 350 && y <= 380) {
                // Volver al menú principal
                return;
            } else {
                continue; // Si no se selecciona ninguna opción válida, sigue esperando.
            }

            // Abrir la URL en el navegador predeterminado
            if (system(("start " + url).c_str()) != 0) {
                cerr << "Error al abrir la red social seleccionada.\n";
            }
        }
    }
}

void cargarAsistenteVirtual() {
    initwindow(800, 600, "Galaxy Virtual Assistant");

    // Alineación del texto "Galaxy se esta inicializando..."
    setcolor(GREEN);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3); // Ajustar el tamaño de la fuente para centrado
    outtextxy(260, 200, "Galaxy se esta inicializando...");

    // Dibujar marco de la barra de progreso (alineado en el centro)
    rectangle(250, 250, 520, 270);  // Ajustamos las coordenadas para centrar la barra
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(251, 251, GREEN);

    // Animación de la barra de progreso (alineada al centro de la ventana)
    for (int i = 251; i <= 520; i++) {
        setfillstyle(SOLID_FILL, GREEN);
        bar(250, 250, i, 270);  // Llenar la barra de progreso
        delay(10);               // Retraso para la animación
    }

    // Esperar un momento antes de pasar al menú principal
    delay(1000); // Un retraso mayor para visualizar la barra completada

    while (true) {
        dibujarMenu();
        string frase = "Bienvenido usuario, ingresa una opcion";
    	hablar(frase);

        // Esperar clic del usuario
        int x, y;
        while (!ismouseclick(WM_LBUTTONDOWN)) delay(50);
        getmouseclick(WM_LBUTTONDOWN, x, y);

        int opcion = detectarOpcion(x, y);

        if (opcion == 0) continue; // Si no se hace clic en una opción, seguir esperando

        cleardevice(); // Limpiar pantalla para la acción correspondiente

        switch (opcion) {
        case 1:
            subMenuNavegacionWeb();
            break;
        case 2:
            abrirPrograma();
            break;
        case 3:
            subMenuBuscadorMusica();
            break;
        case 4:
            subMenuRedSocial();
            break;
        case 5:
            closegraph();
            return; // Salir del programa
        default:
            outtextxy(200, 400, "Opcion no valida. Intenta de nuevo.");
        }
    }

    closegraph(); // Cerrar ventana gráfica
}

int main() {
	cargarAsistenteVirtual();
    return 0;
}