#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// must add file handling (add timer to provide the time when that operation happened)
void mainoptions();

int choose_calc(){
    printf("1: Simple Calculator\n2: Scientific Calculator\n3: Encoding and decoding of a word\n0: End the program\nChoose Option: ");
    int x;
    scanf("%d", &x);
    return x;
}
// get the option from the user for the simple calculator
int get_option1(){
    printf("1: Adding two numbers x, y\n2: Subtracting two numbers x, y\n3: Multiplying two numbers x, y\n4: Deviding two numbers x, y\n5: Modulus of x / y\n6: Back to the Main Menu\n0: End the program\nChoose Option: ");
    int x;
    scanf("%d", &x);
    return x;
}
// get the option from the user for the scientific calculator
int get_option2(){
    printf("1: Square root of number x\n2: Prime factorization of number x\n3: Factorial of number x\n4: log of number x\n5: ln of number x\n6: Yth power of number x\n7: Sin of number x\n8: Cos of number x\n9: Tan of number x\n10: Sin^-1 x\n11: Cos^-1 x\n12: Tan^-1 x\n13: Solving first degree equation\n14: Solving second degree equation\n15: Back to the Main Menu\n0: End the program\nChoose Option: ");
    int x;
    scanf("%d", &x);
    return x;
}

// defining a structure for two numbers x , y
typedef struct xy{
    double x,y;
}xy;


// get the two double numbers from the user
xy getxy(){
    xy v;
    printf("x: ");
    scanf("%lf", &v.x);
    printf("y: ");
    scanf("%lf", &v.y);
    return v;
}

// get an integer number from the user
int getint(){
    int x;
    printf("x: ");
    scanf("%d", &x);
    return x;
}

// get a double number from the user
double getdouble(){
    double x;
    printf("x: ");
    scanf("%lf", &x);
    return x;
}


// addition function
double addition(){
    printf("..Addition x + y..\n");
    xy xandy = getxy();
    double z = xandy.x + xandy.y;
    return z;
}
// subtraction function
double subtraction(){
    printf("..Subtraction x - y..\n");
    xy xandy = getxy();
    double z = xandy.x - xandy.y;
    return z;
}
// multiplication
double multiplication(){
    printf("..multiplication x * y..\n");
    xy xandy = getxy();
    double z = xandy.x * xandy.y;
    return z;
}
// division
double division(){
    printf("..Division x / y..\n");
    xy xandy = getxy();
    double z = xandy.x / xandy.y;
    return z;
}

double modulus(){
    printf("..modulus \n");
    xy xandy = getxy();
    double z = remainder(xandy.x, xandy.y);
    if (z < 0){
        z = z + xandy.y;
    }
    return z;
}

double squareroot(){
    printf("..Square root..\n");
    double result;
    result = sqrt(getdouble());
    return result;
}
 // I should limit the input of the function to be less than 32.
int factorial(){
    printf("..Factorial x!..\n");
    int x = getint();
    int factorial = 1;
    for(int i = 1; i <= x; i++){
        factorial *= i;
    }
    return factorial;
}

void primeFactor(){
    printf("..Prime factors of x..\n");
    int x = getint();
    int divisor;
    divisor = 2;
    while (x > 1) {
        if (x % divisor == 0) { /* if divisible */
            printf("%d|%d\n", x, divisor);
            x = x / divisor;
        }
        else
            divisor = divisor + 1;  /* not divisable */
    }
    printf("%d\n", 1);
}

// log
double logg(double x){
    double result = log10(x);
    return result;
}
// ln
double lnn(double x){
    double result = log(x);
    return result;
}
// power
double power(xy xy1){
    double result = pow(xy1.x, xy1.y);
    return result;
}
//sin
double sinn(double x){
    double rad = x * M_PI / 180;
    double result = sin(rad);
    return result;
}
//cos
double coss(double x){
    double rad = x * M_PI / 180;
    double result = cos(rad);
    return result;
}
//tan
double tann(double x){
    double rad = x * M_PI / 180;
    double result = tan(rad);
    return result;
}

void angleS(){
    double x = getdouble();
    double y = asin(x);
    printf("The angle is %.2f rads or %.2f degrees\n", y, y * 180 / M_PI);
}

void angleC(){
    double x = getdouble();
    double y = acos(x);
    printf("The angle is %.2f rads or %.2f degrees\n", y, y * 180 / M_PI);
}

void angleT(){
    double x = getdouble();
    double y = atan(x);
    printf("The angle is %.2f rads or %.2f degrees\n", y, y * 180 / M_PI);
}
//solving first degree equation
double feq(){
    printf("...Solving first degree equation in the form Y = aX + c...\n");
    double a, c, solution;
    printf("Enter the cofficient of x  a: ");
    scanf("%lf", &a);
    printf("Enter the pure cofficient c: ");
    scanf("%lf", &c);
    solution = -c / a;
    printf("The solution is %.2f.", solution);

}

void seq(){
    printf("...Solving first degree equation in the form Y = aX + b...\n");
    double a, b, c, determinant, x1, x2;
    printf("Enter the cofficient of x2  a: ");
    scanf("%lf", &a);
    printf("Enter the cofficient of x  b: ");
    scanf("%lf", &b);
    printf("Enter the pure cofficient c: ");
    scanf("%lf", &c);
    determinant = (b * b) - (4 * a * c);
    if(determinant > 0){
        x1 = ((-1 * b + sqrt(determinant))/(2 * a));
        x2 = ((-1 * b - sqrt(determinant))/(2 * a));
        printf("There are two solutions, which are %.2f and %.2f", x1, x2);
    }else if(determinant == 0){
        x1 = ((-1 * b)/ (2 * a));
        printf("There is one solution, which is %.2f", x1);
    }else{
        printf("There are no real solutions for that equaiton.");
    }

}


void simple_calc(){
    int y = 1;
    while(y != 0 || y != 6){
       int x = get_option1();
        switch (x){
            case 0:
            y = 0;
            printf("...The program is Ending...\n");
            printf("..........Thanks..........\n");
            break;
            case 1:
            printf("The sum is: %.2lf\n\n", addition());
            break;
            case 2:
            printf("The result is: %.2lf\n\n", subtraction());
            break;
            case 3:
            printf("The result is: %.2lf\n\n", multiplication());
            break;
            case 4:
            printf("The result  is: %.2lf\n\n", division());
            break;
            case 5:
            printf("The modulus  is: %.2lf\n\n", modulus());
            break;
            case 6:
            printf("..Main Menu..\n");
            mainoptions();
            break;
            default:
            printf("\n\nPlease choose correct option!!\n");
            break;
        }
    }

}

void scientific_calc(){
    int y = 1;
    while(y != 0 || y != 12){
       int x = get_option2();
        switch (x){
            case 0:
            y = 0;
            printf("...The program is Ending...\n");
            printf("..........Thanks..........\n");
            break;
            case 1:
            printf("The square root is: %.2lf\n\n", squareroot());
            break;
            case 2:
            primeFactor();
            break;
            case 3:
            printf("The factorial is %d\n\n", factorial());
            break;
            case 4:
            printf("The log is %.2lf\n\n", logg(getdouble()));
            break;
            case 5:
            printf("The ln is %.2lf\n\n", lnn(getdouble()));
            break;
            case 6:
            printf("The result is %.2lf\n\n", power(getxy()));
            break;
            case 7:
            printf("The sin is %.2lf\n\n", sinn(getdouble()));
            break;
            case 8:
            printf("The cos is %.2lf\n\n", coss(getdouble()));
            break;
            case 9:
            printf("The tan is %.2lf\n\n", tann(getdouble()));
            break;
            case 10:
            angleS();
            break;
            case 11:
            angleC();
            break;
            case 12:
            angleT();
            break;
            case 13:
            feq();
            printf("\n\n");
            break;
            case 14:
            seq();
            printf("\n\n");
            break;
            case 15:
            printf("..Main Menu..\n");
            mainoptions();
            break;
            default:
            printf("\n\nPlease choose correct option!!\n");
            break;
        }
    }

}

void encode_decode(){
    char ch[100], e[100], d[100];
    int i, j;
    printf ("Enter your word: ");
    scanf("%s", ch);
    for(i=0;i<strlen(ch);i++){
        if((ch[i]>='a'&&ch[i]<='x')||(ch[i]>='A'&&ch[i]<='X')){

            e[i]=ch[i]+2;
        }else if(ch[i]=='y'||ch[i]=='z'||ch[i]=='Y'||ch[i]=='Z'){
            e[i]=ch[i]-24;
        }else{
            e[i]=ch[i];
        }
    }
    e[i]='\0';
    printf ("The word encoded is: %s\n",e);
    for(i=0;i<strlen(ch);i++){
        if((e[i]>='c'&&e[i]<='z')||(e[i]>='C'&&e[i]<='Z')) {
            d[i]=e[i]-2;
        }else if(e[i]=='a'||e[i]=='b'||e[i]=='A'||e[i]=='B'){
            d[i]=e[i]+24;
        }else{
            d[i]=e[i];
        }
    }
    d[i]='\0';
    printf ("The word decoded (original) is: %s\n",d);
    printf("\n");
}





void mainoptions(){
    int y = 1;
    while(y != 0){
       int x = choose_calc();
        switch (x){
            case 0:
            y = 0;
            printf("...The program is Ending...\n\n\n");
            printf("          Thanks\n");
            break;
            case 1:
            simple_calc();
            break;
            case 2:
            scientific_calc();
            break;
            case 3:
            encode_decode();
            printf("..Main Menu..\n");
            //coding and decoding
            break;
            case 4:
            //qr generator
            break;
            case 5:
            //unit conversion
            break;
            case 6:
            //first degree diffrential
            break;
            default:
            printf("\n\nPlease choose correct option!!\n");
            break;
        }
    }
}

int main(){
    mainoptions();
    return 0;
}


