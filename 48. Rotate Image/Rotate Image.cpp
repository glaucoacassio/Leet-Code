/*
Explicacao da Solucao

i = 0, j = 0;
temp = matrix[0][0]; //1
matriz[0][0] = matriz[0][0]; //1
matriz[0][0] = temp; //1

i = 0, j = 1;
temp = matrix[0][1]; //2
matrix[0][1] = matrix[1][0]; //matrix[1][0] = 4 entao 2 e 4 sao trocados
matrix[1][0] = temp; //matrix[1][0] = 4 entao 2 e 4 sao trocados

i = 0, j = 2;
temp = matrix[0][2]; //3
matrix[0][2] = matrix[2][0]; //matrix[2][0] = 7 entao 3 e 7 sao trocados
matrix[2][0] = temp; //matrix[2][0] = 7 entao 3 e 7 sao trocados

A ideia era primeiramente transpor a matriz e entao trocar ela simetricamente. Para essa instancia:
1 2 3
4 5 6
7 8 9

depois de transpor eu vou trocar, caso queira pode usar o swap(matrix[i][j], matrix[j][i])
1 4 7
2 5 8
3 6 9

entao eu giro a matriz horizontalmente. swap(matrix[i][j], matrix[i][matrix.size()-1-j])
7 4 1
8 5 2
9 6 3
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = i; j < matrix.size(); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < (matrix.size()/2); j++)//Divido por 2 porqu é o meio da matriz
            {
                int temp = matrix[i][j];//elemento atual
                /*
                O elemento atual é igual ao comprimento final 
                então o valor da coluna inicial, o primeiro ponto 
                é igual ao segundo ponto que está começando do final.
                Entao nos fazemos o comprimento - 1 e obtemos a
                posicao do indice j e isso vai ser a mesma distancia
                do inicio pro fim desses pontos.
                ...
                Entao é isso troco os elementos da matriz causando um giro 
                e depois troco os pontos das colunas.
                */
                matrix[i][j] = matrix[i][matrix.size()-1-j];//
                matrix[i][matrix.size()-1-j] = temp;
            }
        }
    }
};
