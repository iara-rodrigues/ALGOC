# ALGOC
<p> A Language to Generate Only Constants </p>

<p> Desenvolvido por Iara Rodrigues Grigorio Oliveira Silva.</p>

<h2> O problema</h2>
<p>ALGOC - A Language to Generate Only Constants. Esta linguagem é bem simples, e tem apenas quatro construtores: </p>
<ul>
  <li>PLUSONE - cria a constante 1 (positivo)</li>
  <li>MINUSONE - cria a constante -1 (negativo)</li>
  <li>INC - adiciona um à constante criada</li>
  <li>DUP - multiplica a constante criada por dois</li>
</ul>
<p>Um programa nesta linguagem é uma sequência destes construtores, um para cada linha, executados sequencialmente. Os programas escritos nesta linguagem devem ser simples, curtos e rápidos. Para atingir esta meta, existem as seguintes regras:</p>
<ul>
  <li>Cada programa deve começar obrigatoriamente com PLUSONE ou MINUSONE</li>
  <li>As constantes devem ser geradas com o menor número de instruções possíveis</li>
  <li>Se uma constante C pode ser gerada com mais de um programa (com o mesmo número
  de instruções), então o programa mais rápido deve ser utilizado. Para este propósito,
  suponha que a instrução DUP é executada em T nanosegundos e a instrução INC em 2T
  nanosegundos</li>
</ul>
  
<h2> Observações </h2>
<ul>
<li> Depois de um certo número de linhas no arquivo de entrada o programa fecha sozinho.</li>
<li> O programa foi implementado no Windows.</li>
</ul>

<h2> Documentação </h2>
<h3><b> Main </b></h3>
<p>Na função main, eu começo abrindo o arquivo de leitura e calculando o número de linhas contidas nele. Após feito isso, eu o fecho e abro o arquivo de saída (arquivo no qual ficará com as respostas salvas). Chamo a função 'imprimeConstrutoresArquivo' para imprimir as respostas e, se chegar no número 0 no arquivo de leitura o programa acaba, como foi pedido no documento da avaliação. Mas se quiser que o programa continue rodando, basta comentar a linha que contem o 'break;'.</p>

<h3><b> Função Construtores </b></h3>
<p> Nessa função contém a lógica do ALGOC. </p>
<p> Fiz uma parte para os números 1 e -1, já que seus construtores é apenas o PLUSONE ou o MINUSONE.</p>
<p> Para encontrar os construtores dos números positivos eu crio uma variável chamada novoNum, para que, a partir dela, eu possa saber quanto está dando a conta dos contrutores. Como para os números positivos não possui uma maneira de abaixar o valor do novoNum, eu uso a condição que, antes de *2 eu confiro se vai passar do valor do num (número provindo do algoc.in). </p>
<p> Para encontrar os construtores dos números negativos, eu tirei a condição do "do-while" ser feito apenas se o novoNum for menor que num, até por que, com os números negativos é possível subtrair. E, para encontrar resultados com um menor número de construtores, eu coloquei uma condição na hora de multiplicar.</p>
<p> Após encontrado todos os construtores, eu coloco um zero na última posição do array tipo[]. Isso será usado na função 'tamanho'.  </p>

<h3><b> Função Tamanho </b></h3>
<p> Fiz essa função para encontrar o tamanho do array gerado pela função 'contrutores'. Tentei encontrar esse valor de outras maneiras, mas preferi fazendo assim.</p>
<p> Pode-se perceber que usei aquela última posição do array igual a zero para encontrar o tamanho.</p>

<h3><b> Função ImprimeConstrutoresArquivo </b></h3>
<p> Essa função foi criada para imprimir os construtores com seus respectivos nomes. </p>
<ol type = 1>
  <li>PLUSONE</li>
  <li>MINUSONE</li>
  <li>INC</li>
  <li>DUP</li>
</ol> 
