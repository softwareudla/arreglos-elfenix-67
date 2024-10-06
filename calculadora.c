//LIBRERIAS USADAS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> 
//DEFINIR LAS VARIABLES DE LOGO Y SUS COLORES
#define COLOR_ROJO "\033[31m"      
#define COLOR_AZUL "\033[34m"      
#define COLOR_VERDE "\033[32m"     
#define COLOR_BLANCO "\033[37m"   
#define COLOR_RESET "\033[0m"    
// ASIGNATURAS Y ESTUDIANTES 
#define estu 5  
#define asig 3  

// Animaci¢n de impresi¢n del logo
void imprimir_con_animacion(const char *texto) {
    while (*texto) {
        putchar(*texto++);
        fflush(stdout); 
        usleep(10000); 
    }
}
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}
void imprimir_cuadro_resultados(int promedios[], int maximos[], int minimos[]) {
    int aprobados = 0;  
    int reprobados = 0;  
    
    printf("\n");
    printf(COLOR_BLANCO "*********************************************************************************\n");
    printf("*                               " COLOR_ROJO "Resultados" COLOR_BLANCO "                                      *\n");
    printf(COLOR_BLANCO "*********************************************************************************\n");
    
    for (int i = 0; i < estu; i++) {
        printf("* Estudiante %d:                                                                 *\n", i + 1);
        printf("*   Promedio: %2d                                                                *\n", promedios[i]);
        printf("*   Calificaci¢n m s alta: %2d                                                   *\n", maximos[i]);
        printf("*   Calificaci¢n m s baja: %2d                                                   *\n", minimos[i]);
        if (promedios[i] >= 6) {
            printf("*   Estado: " COLOR_VERDE "Aprobado" COLOR_BLANCO "                                                            *\n");
            aprobados++;
        } else {
            printf("*   Estado: " COLOR_ROJO "Reprobado" COLOR_BLANCO "                                                            *\n");
            reprobados++;
        }

        printf(COLOR_BLANCO "*********************************************************************************\n");
    }
    
    printf(COLOR_BLANCO "*********************************************************************************\n"); // L¡nea final del cuadro
    printf("* Total de aprobados: %2d                                                        *\n", aprobados);
    printf("* Total de reprobados: %2d                                                       *\n", reprobados);
    printf(COLOR_BLANCO "*********************************************************************************\n"); // Cierre del cuadro final
}

int main() {
    // LOGO
    char *pattern[] = {
        COLOR_VERDE " ######     ###    ##        ######  ##     ## ##          ###    ########   #######  ########     ###    ",
        COLOR_VERDE "##    ##   ## ##   ##       ##    ## ##     ## ##         ## ##   ##     ## ##     ## ##     ##   ## ##   ",
        COLOR_BLANCO "##        ##   ##  ##       ##       ##     ## ##        ##   ##  ##     ## ##     ## ##     ##  ##   ##  ",
        COLOR_BLANCO "##       ##     ## ##       ##       ##     ## ##       ##     ## ##     ## ##     ## ########  ##     ## ",
        COLOR_BLANCO "##       ######### ##       ##       ##     ## ##       ######### ##     ## ##     ## ##   ##   ######### ",
        COLOR_VERDE "##    ## ##     ## ##       ##    ## ##     ## ##       ##     ## ##     ## ##     ## ##    ##  ##     ## ",
        COLOR_VERDE " ######  ##     ## ########  ######   #######  ######## ##     ## ########   #######  ##     ## ##     ## "
    };

    int rows = sizeof(pattern) / sizeof(pattern[0]);

    for (int i = 0; i < rows; i++) {
        imprimir_con_animacion(pattern[i]);
        printf("\n"); 
    }

    
    printf("\n\n");

    printf(COLOR_BLANCO "*********************************************************************************\n");
    printf("*                            " COLOR_ROJO "Descripci¢n del Problema:" COLOR_BLANCO "                          *\n");
    printf("* "COLOR_AZUL"  Una escuela desea implementar un programa en C que le permita gestionar las"COLOR_BLANCO" *\n");
    printf("* "COLOR_AZUL"calificaciones de un grupo de estudiantes en varias asignaturas. Adem s de  "COLOR_BLANCO"  *\n");
    printf("*"COLOR_AZUL" gestionar las calificaciones, el programa debe calcular y mostrar informaci¢n"COLOR_BLANCO" *\n");
    printf("*"COLOR_AZUL" relevante como el promedio de calificaciones por estudiante y por asignatura,"COLOR_BLANCO" *\n");
    printf("* "COLOR_AZUL"la calificaci¢n m s alta y baja, y cu ntos estudiantes aprobaron cada       "COLOR_BLANCO"  *\n");
    printf("* "COLOR_AZUL"asignatura.                                                                 "COLOR_BLANCO"  *\n");
    printf(""COLOR_BLANCO"*********************************************************************************\n" COLOR_RESET);

    // Definici¢n de variables
    int cal[estu][asig]; 
    int suma, promedio;   
    int max, min;         
    int promedios[estu];  
    int maximos[estu];    
    int minimos[estu];    
    // Entrada de calificaciones
    for (int i = 0; i < estu; i++) {
        for (int j = 0; j < asig; j++) {
            bool valido = false;
            while (!valido) {
                printf("Ingrese la calificaci¢n del estudiante %d para la asignatura %d (1-10): ", i + 1, j + 1);
                
                char entrada[10];
                if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
                    int calificacion = strtol(entrada, NULL, 10);
                    
                    if (calificacion >= 1 && calificacion <= 10) {
                        cal[i][j] = calificacion;
                        valido = true; 
                    } else {
                        printf("Error: La calificaci¢n debe ser un n£mero entero entre 1 y 10. Int‚ntalo de nuevo.\n");
                    }
                } else {
                    printf("Error de entrada. Int‚ntalo de nuevo.\n");
                }

                limpiar_buffer();
            }
        }
    }

    for (int i = 0; i < estu; i++) {
        suma = 0;
        max = 0;
        min = 10;
        for (int j = 0; j < asig; j++) {
            suma += cal[i][j];
            if (cal[i][j] > max) max = cal[i][j];
            if (cal[i][j] < min) min = cal[i][j];
        }
        promedio = suma / asig;
        promedios[i] = promedio;  
        maximos[i] = max;         
        minimos[i] = min;          
    }

    imprimir_cuadro_resultados(promedios, maximos, minimos);

    return 0;
}
