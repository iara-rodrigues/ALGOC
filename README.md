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
<li> Por algum motivo, só pode ter até 7 linhas no arquivo de entrada (um número por linha). Se tiver mais linhas o programa fecha.</li>
<li> O programa foi implementado no Windows.</li>
</ul>

<h2> Documentação </h2>
<h3><b> Main </b></h3>
<p>Na função main, eu começo abrindo o arquivo de leitura e calculando o número de linhas contidas nele. Após feito isso, eu o fecho e abro o arquivo de saída (arquivo no qual ficará com as respostas salvas). Chamo a função 'imprimeConstrutoresArquivo' para imprimir as respostas e, se chegar no número 0 no arquivo de leitura o programa acaba, como foi pedido no documento da avaliação. Mas se quiser que o programa continue rodando, basta comentar a linha que contem o 'break;'.</p>

<h3><b> Função Construtores </b></h3>
<p> Nessa função contém a lógica do ALGOC. </p>
<p> Fiz uma parte para os números 1 e -1, já que seus construtores é apenas o PLUSONE ou o MINUSONE.</p>
<p> Para encontrar os construtores dos números positivos eu crio uma variável chamada novoNum, para que, a partir dela, eu possa saber quanto está dando a conta dos contrutores. Como para os números positivos não possui uma maneira de abaixar o valor do novoNum, eu uso a condição que, antes de multiplicar por 2 eu confiro se vai passar do valor do num (número provindo do algoc.in). Além disso, criei as variaveis 'count', 'seg' e 'i' ou 'a'.</p>
<ul>
  <li> <b>count:</b> Ela foi criada para poder saber quantos construtores teria para o número, partindo de duas lógicas diferentes. No final, eu comparo 'count1' e 'count2' para ver qual foi menor, visto que essa é uma das regras do programa.</li>
  <li> <b>seg: Essa variável foi criada para caso 'count1' seja igual à 'count2', então é exibido o resultado de conjunto de construtores que os segundo para executá-lo seja menor. Lembrando que DUP = 1s e INC = 2s.</b> </li>
  <li> <b>i ou a:</b> Essas são as variáveis de incrementação para que seja possível saber o índice dos elementos.</li>
</ul>
<p> Ainda na lógica dos números positivos, foi criado dois arrays 'tipo[]' e 'tipo1[]' para salvar os construtores encontrados e salvar no array de retorno ('tipoResult[]') somente quando soubesse que aquela sequência de contrutores era a menor e mais rápida.
<p> Para encontrar os construtores dos números negativos, eu tirei a condição do "do-while" ser feito apenas se o 'novoNum' for menor que 'num', até por que, com os números negativos é possível subtrair. E, para encontrar resultados com um menor número de construtores, eu coloquei uma condição na hora de multiplicar, logo, para esse números eu não usei a mesma lógica dos números positivos e também não precisei criar as variáveis 'count' e 'seg'.</p>
<p> Após encontrado todos os construtores, eu coloco um zero na última posição do array 'tipoResult[]'. Isso será usado na função 'tamanho'.  </p>

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
