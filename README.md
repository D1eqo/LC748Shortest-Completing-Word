# LC748Shortest-Completing-Word

Diego Aquino Montero, turma M1

1 - 748_Shortest_Completing_Word.c é o código completo com o main().

2 - 748lcFeitoEmAula.c é o que eu consegui fazer no período de aula no dia 7 de Julho.

3 - codigo do leet 748 é a versão aceita pelo LeetCode, sem main() e libraries.

4 - littletest2.c é uma versão simplificada do desafio com a estrutura do main improvisada para funcionar com o resto do código.


Descrição do LeetCode:
Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".
Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

Casos testados:
Todos os casos do LeetCode estão funcionando.
Casos criados por mim no Vscode também funcionam

Como funciona meu código:

1 - Dentro do 'char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize)' a função 'GetLetters' recebe a 'licensePlate' e o resultado é recebido por 'freePlate', uma versão composta apenas por letras do 'licensePlate'; as letras maiúsculas são convertidas para minúsculas usando a expressão 'tolower'.

2 - Um 'for' se repetirá para cada palavra em 'words[]', dentro há duas expressões 'if'. O primeiro 'if' avalia se a string de 'words[]' atual possuí a quantidade de letras mínima para ser aceito em relação a 'frePlate', esta avaliação é feita através da função 'CheckForWords'.

3 - Dentro de 'CheckForWords' um contador irá somar o valor de +1 para pontuar a aparição de uma letra específica em 'freePlate', este contador é 'counter[26]', o valor de 26 se refere às letras do alfabeto. Por exemplo, caso a letra 'a' se repita duas vezes em 'freePlate' então o counter[0], correspondente a 'a', irá somar +1 duas vezes.

4 - Depois disso, uma a string recebida em 'words' será testada similarmente à anterior. Desta vez, no entanto, para cada letra em 'words[i]' o 'counter[]' diminuirá.

5 - Se o valor do 'counter[]' para todas as letras for 0, significa que a palavra 'words' tem letras suficientes para satisfazer a função e retornar true. Caso contrário retorna-se false.

6 - Se a função 'CheckForWords' retornou true a palavra 'words[]' usada na função será testada para ver se é menor ou maior que a string em 'shortest', originalmente com valor NULL, se sim a words[] será passada para shortest.

7 - Após todas as palavras em words[] serem testadas o conteúdo de 'shortest' deve ser igual à palavra que satisfaz o problema.

