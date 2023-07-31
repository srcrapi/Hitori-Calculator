/*
    Hitori Calculates everything :D

    +──────────────────────────+
    |    ____             _    |
    |   |  _ \ __ _ _ __ / |   |         
    |   | |_) / _` | '_ \| |   |
    |   |  _ < (_| | |_) | |   |
    |   |_| \_\__,_| .__/|_|   |
    |            |_|           |
    +──────────────────────────+
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

typedef enum CallerType{
    SUM,
    SUBTRACT,
    DIVIDE,
    MULTIPLY,
    RAISED,
    SQUARE_ROOT
}cType;

void menu(); //Informa o compilador que existe uma funçao menu para nao dar erros posteriormente

float value1, value2, result;

void values(float* value1, float* value2, const cType caller){ //Criaçao da variavel caller para ver quem chamou pela funçao

    if (caller == RAISED){

        printf("\n-> Enter the value: ");
        scanf("%f", value1);

        printf("\n-> Enter the raised value: ");
        scanf("%f", value2);
    }
    else{
        printf("\n-> Enter the first value: ");
        scanf("%f", value1);

        if (value2 != NULL && caller != RAISED){
        
        printf("\n-> Enter the second value: ");
        scanf("%f", value2);
    }
    }
    
}

void systemVerification(){
    
    #ifdef _WIN32
        system("pause");
        system("cls");

    #else
        printf("Pressione qualquer tecla para continuar...");
        system("read -n 1 -s -r -p \"\"");
        system("clear");
    
    #endif
}

void sum(){

    values(&value1, &value2, SUM);

    result = value1 + value2;

    printf("\n--> Result: %2.f +%2.f = %2.f\n\n", value1, value2, result);
    
    systemVerification();

    menu();
}

void subtract(){

    values(&value1, &value2, SUBTRACT);

    result = abs(value1 - value2); //Assim vai ficar sempre na ordem certa, pega o absoluto

    printf("\n-> Result %2.f -%2.f = %2.f\n\n", value1, value2, result);

    systemVerification();

    menu();
}

void divide(){

    values(&value1, &value2, DIVIDE);

    result = value1 / value2; //Variavel para guardar a divisao

    printf("\n-> Result: %2.f /%2.f = %2.f\n\n", value1, value2, result);

    systemVerification();

    menu();
}

void multiply(){

    values(&value1, &value2, MULTIPLY);

    result = value1 * value2; //Variavel para guardar a multiplicaçao

    printf("\n-> Result: %2.f x%2.f = %2.f\n\n", value1, value2, result);

    systemVerification();

    menu();
}

void raised(){

    values(&value1, &value2, RAISED);

    result = pow(value1, value2);

    printf("\n-> Result: %2.f\n\n", result);

    systemVerification();

    menu();
}

void squareRoot(){

    values(&value1, NULL, SQUARE_ROOT);

    result = sqrt(value1);

    printf("\n-> Result: %2.f\n\n", result);

    systemVerification();

    menu();
}

void menu(){

    int option;

    printf("\nWelcome to Hitori Calculator!\n\n");

    while (option != 7){

        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#           Hitori Calculator 1.0           #\n");
        printf("#                                           #\n");
        printf("#              1 : Addition                 #\n");
        printf("#              2 : Subtraction              #\n");
        printf("#              3 : Division                 #\n");
        printf("#              4 : Multiplication           #\n");
        printf("#              5 : Raised                   #\n");
        printf("#              6 : Square Root              #\n");
        printf("#              7 : Exit                     #\n");
        printf("#                                           #\n");
        printf("#############################################\n\n");

        printf("-> ");
        scanf("%d", &option);

        switch(option){

            case 1:
                sum();
            break;

            case 2:
                subtract();
            break;

            case 3:
                divide();
            break;

            case 4:
                multiply();
            break;

            case 5:
                raised();
            break;

            case 6:
                squareRoot();
            break;
            
            case 7:
                Sleep(500);
                printf("\nExiting.");

                for (int i = 0; i < 6; i++){
                    Sleep(300);
                    printf(".");
                }
                Sleep(500);
                exit(1);
            break;

            default:
                printf("\nInvalid value.\n\n");
                Sleep(1500);
            break;
        }
    }

}

int main(){

    menu(); //Chama o menu

    return 0;
}