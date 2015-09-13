#include <bits/stdc++.h>
using namespace std;
 
string cad;
char res[10002];
int apunt;
int cont;
 
int main (){
     
    freopen ("auxiliary.in", "r", stdin);
    freopen ("auxiliary.out", "w", stdout);
    cin >> cad;
    for (int i = 0; i < cad.size(); i++){
        if (apunt >= 1){
            if (cad[i] == '('){
                cont++;
                if (res[apunt] == '('){
                    apunt++;
                    res[apunt] = '(';
                }else{
                    if (res[apunt] == '+'){
                        apunt++;
                        res[apunt] = '(';
                    }else{
                        if (res[apunt] == ')'){
                            apunt++;
                            res[apunt] = '+';
                            apunt++;
                            res[apunt] = '(';
                        }else{
                            apunt++;
                            res[apunt] = '+';
                            apunt++;
                            res[apunt] = '(';
                        }
                    }
                }
            }
            if (cad[i] == ')'){
                if (res[apunt] == '('){
                    apunt++;
                    res[apunt] = '0';
                    apunt++;
                    res[apunt] = ')';
                    cont--;
                }else{
                    if (res[apunt] == ')'){
                        if (cont){
                            apunt++;
                            res[apunt] = ')';
                            cont--;
                        }else{
                            apunt++;
                            res[apunt] = '+';
                            apunt++;
                            res[apunt] = '(';
                            apunt++;
                            res[apunt] = '0';
                            apunt++;
                            res[apunt] = ')';
                        }
                    }else{
                        if (res[apunt] == '+'){
                            if (cont){
                                apunt++;
                                res[apunt] = '0';
                                apunt++;
                                res[apunt] = ')';
                                cont--;
                            }else{
                                apunt++;
                                res[apunt] = '(';
                                apunt++;
                                res[apunt] = '0';
                                apunt++;
                                res[apunt] = ')';
                                 
                            }
                        }else{
                            if (cont){
                                apunt++;
                                res[apunt] = ')';
                                cont--;
                            }else{
                                apunt++;
                                res[apunt] = '+';
                                apunt++;
                                res[apunt] = '(';
                                apunt++;
                                res[apunt] = '0';
                                apunt++;
                                res[apunt] = ')';
                            }
                        }
                    }
                }
            }
            if (cad[i] == '+'){
                if (res[apunt] == '('){
                    apunt++;
                    res[apunt] = '0';
                    apunt++;
                    res[apunt] = '+';
                }else{
                    if (res[apunt] == ')'){
                        apunt++;
                        res[apunt] = '+';
                    }else{
                        if (res[apunt] == '+'){
                            apunt++;
                            res[apunt] = '0';
                            apunt++;
                            res[apunt] = '+';
                        }else{
                            apunt++;
                            res[apunt] = '+';
                        }
                    }
                }
            }
            if (cad[i] != '(' && cad[i] != ')' && cad[i] != '+'){
                if (res[apunt] == '('){
                    apunt++;
                    res[apunt] = cad[i];
                }else{
                    if (res[apunt] == ')'){
                        apunt++;
                        res[apunt] = '+';
                        apunt++;
                        res[apunt] = cad[i];
                    }else{
                        if (res[apunt] == '+'){
                            apunt++;
                            res[apunt] = cad[i];
                        }else{
                            apunt++;
                            res[apunt] = cad[i];
                        }
                    }
                }
            }
        }else{
            if (cad[i] == '(')
                cont++;
            apunt++;
            res[apunt] = cad[i];
        }
    }
    while (cont){
        if (res[apunt] == '('){
            apunt++;
            res[apunt] = '0';
            apunt++;
            res[apunt] = ')';
            cont--;
        }else{
            if (res[apunt] == ')'){
                if (cont){
                    apunt++;
                    res[apunt] = ')';
                    cont--;
                }else{
                    apunt++;
                    res[apunt] = '+';
                    apunt++;
                    res[apunt] = '(';
                    apunt++;
                    res[apunt] = '0';
                    apunt++;
                    res[apunt] = ')';
                }
            }else{
                if (res[apunt] == '+'){
                    if (cont){
                        apunt++;
                        res[apunt] = '0';
                        apunt++;
                        res[apunt] = ')';
                        cont--;
                    }else{
                        apunt++;
                        res[apunt] = '(';
                        apunt++;
                        res[apunt] = '0';
                        apunt++;
                        res[apunt] = ')';
                         
                    }
                }else{
                    if (cont){
                        apunt++;
                        res[apunt] = ')';
                        cont--;
                    }else{
                        apunt++;
                        res[apunt] = '+';
                        apunt++;
                        res[apunt] = '(';
                        apunt++;
                        res[apunt] = '0';
                        apunt++;
                        res[apunt] = ')';
                    }
                }
            }
        }
    }
    if (res[apunt] == '('){
        apunt++;
        res[apunt] = '0';
        apunt++;
        res[apunt] = ')';
    }else{
        if (res[apunt] == '+'){
            apunt++;
            res[apunt] = '0';
        }
    }
    if (res[1] == ')' && apunt >= 1){
        printf ("(0");
    }else{
        if (res[1] == '+' && apunt >= 1)
            printf ("0");
    }
    for (int i = 1; i <= apunt; i++)
        printf ("%c", res[i]);
    printf ("\n");
    return 0;
}
