class Solution {
public:
    bool isPalindrome(int x) {
      	long long int aux = x;
    	long long int s = 0;

	while (aux != 0)
	{	    
	    s = s * 10 + aux % 10;
	    aux /= 10;
	}
        //Na questao diz que -121 nao é palindromo porque o contrario é 121-
        //E tambem tem que se atentar que 0 é palindromo tambem, foi uma pegadinha caso voce so botasse x > 0.
        //Poderia ser feito com string mas o desafi é fazer com inteiros entao foi como fiz...
	if (x == s && x >= 0) return true;  
	else return false;
    }
};
