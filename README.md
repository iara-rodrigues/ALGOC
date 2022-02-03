# ALGOC
<p> A Language to Generate Only Constants </p>

<p> Desenvolvido por Iara Rodrigues Grigorio Oliveira Silva.</p>

<h2> O problema</h2>
<p>ALGOC - A Language to Generate Only Constants. Esta
linguagem é bem simples, e tem apenas quatro construtores: </p>
<ul>
<li>PLUSONE - cria a constante 1 (positivo)</li>
<li>MINUSONE - cria a constante -1 (negativo)</li>
<li>INC - adiciona um à constante criada</li>
<li>DUP - multiplica a constante criada por dois</li>
</ul>
<p>Um programa nesta linguagem é uma sequência destes construtores, um para cada linha,
executados sequencialmente. Os programas escritos nesta linguagem devem ser
simples, curtos e rápidos. Para atingir esta meta, existem as seguintes regras:</p>
<ul>
<li>Cada programa deve começar obrigatoriamente com PLUSONE ou MINUSONE</li>
<li>As constantes devem ser geradas com o menor número de instruções possíveis</li>
<li>Se uma constante C pode ser gerada com mais de um programa (com o mesmo número
de instruções), então o programa mais rápido deve ser utilizado. Para este propósito,
suponha que a instrução DUP é executada em T nanosegundos e a instrução INC em 2T
nanosegundos</li>
