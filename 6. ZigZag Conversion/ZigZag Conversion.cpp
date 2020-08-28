/*
Se substituir por numeros nessa tabela ver melhor o padrao.
n = numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4

A ideia é identificar um padrão no problema. Se considerarmos o índice de um caractere na saída, observamos alguns padrões:
A primeira chave de cada linha i está presente no índice i da string.
Para a primeira e a última linha, a distância entre cada tecla é (k-1) * 2.
Por exemplo, para k = 4, a diferença é 6.
Portanto, o primeiro elemento da primeira linha está localizado no índice 0, o segundo elemento está localizado no índice 6, 
o terceiro elemento em 12 e assim por diante.
Da mesma forma, o primeiro elemento da última linha está localizado no índice 3, o segundo elemento está localizado no índice 9, 
o terceiro elemento em 15 e assim por diante.
Agora, para todas as linhas do meio, dependendo se estamos subindo ou descendo, o índice difere como é evidente no código abaixo.
*/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1) return s;
        
        int row = 0;
        int incremento = -1;
        for(int i=0; i<s.length(); i++)
        {
        //se eu cheguei num ponto de virada, nos mudamos a direcao de incremento
            if(i%(numRows-1) == 0) incremento*= -1;
            ans[row].push_back(s[i]);
            row += incremento;
        }
        
        string ret;
        for(const auto& res:ans)
            ret += res;
        
        return ret;
    }
};
