# AEDS-Lista de boas-vindas!

<br><h1>Introdução</h1>
<p>Algoritmo guloso (ou míope) é uma solução comum para problemas de otimização, pois realiza a escolha que parece ser a melhor <b>no momento</b>, desde modo, espera-se que uma suceção de boas escolhas irão previnir erros em nível global</p>

<p>Uma matriz é uma estrutura de dados com duas dimensões (i, j) organizada respectivamente em linhas e colunas. A primeira posição da matriz, (matriz[ 0 ][ 0 ]) se encontra sempre no canto superior esquerdo, enquanto a última posição, (matriz[ i ][ j ]) no canto inferior direito. Essa notação mostra que, no caso da <b>primeira</b> posição, se encontra no começo da Linha 0 com a Coluna 0, por isso [ 0 ][ 0 ], enquanto na <b>última posição</b>, ambas já atingiram seu tamanho máximo, digitado pelo ususário. No caso desse algoritmo, apenas trabalharemos com matrizes quadradas, onde o número de linhas é igual ao de colunas. </P>
<h1>Sobre o projeto</h1>
<p>Nesse projeto, o desafio era fazer um algoritmo que
gerasse uma matriz quadrada ( N x N ) preenchida com valores aleatórios para cada posição, onde 'N' é um número inteiro digitado pelo usuário no '<code>main.c</code>' e, a partir de sua primeira posição ([ 0 ][ 0 ]), fosse caminhando até a última ([ N ][ N ]), sempre escolhando o "vizinho" de maior valor para dar o próximo passo. Ao atingir o destino, o algoritmo deve apresentar ao usuário o valor de todas as posições que ele passou somadas em um printf("Soma total: X"); </p>
<h1>Lógica utilizada</h1>
<h2>Criação da matriz</h2>
<p>Para a criação da matriz, foi feita uma função <b>Cria_Matriz()</b> que recebe como parâmetro um número inteiro "Tamanho_matriz", coletado no '<code>main.c</code>' e um inteiro "**matriz", que teve seu devido espaço de memória alocado também no '<code>main.c</code>' através da função malloc(). A matriz é preenchida a partir de 2 loops de for, um de <i>i</i> e o outro de <i>j</i> que, com o auxílio da função externa '<code>rand()</code>' distribui valores aleatórios para cada posição da matriz.
<h2>Movimentação pela matriz<h2>