<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Jogo da Adivinhação em C</h1>
    <p>Este é um simples jogo de adivinhação feito em C.</p>
    <h2>Instruções</h2>
    <ol>
        <li>Para jogar, basta executar o programa em um compilador C.</li>
        <li>Digite 1 para acessar um novo jogo.</li>
        <li>Então tente adivinhar um número entre 1 e 100 escolhido pela máquina.</li>
        <li>Se guie pelas dicas e tente adivinhar no menor número de tentativas possíveis.</li>
    </ol>
    <h2>Estrutura do Código</h2>
    <p>O código é dividido em diferentes funções que são responsáveis por diferentes aspectos do jogo.</p>
    <ul>
        <li>A função <code>menu()</code>:

Essa função exibe as opções disponíveis para o jogador.
Ela imprime na tela as opções do menu, como "Novo Jogo", "Ver Ranking", "Limpar Ranking" e "Sair".</li>
        <li>A função <code>novoJogo()</code>:

Essa função é responsável por executar um novo jogo de adivinhação.
Primeiro, solicita ao jogador que digite seu nome.
Em seguida, o jogador deve escolher um valor entre 1 e 100 para fazer um chute.
O programa gera um número secreto aleatório entre 1 e 100 usando a função <code>rand()</code> e <code>srand(time(NULL))</code> para inicializar a semente aleatória.
Em um loop, o programa compara o chute do jogador com o número secreto e fornece dicas ao jogador para ajustar o próximo chute.
O loop continua até que o jogador adivinhe corretamente o número secreto.
Após o término do jogo, o número de tentativas é exibido na tela.
O nome do jogador e o número de tentativas são armazenados no arquivo "ranking.txt" usando a função <code>fprintf()</code>.</li>
        <li>A função <code>verRanking()</code>:

Essa função lê o arquivo "ranking.txt" que contém os nomes dos jogadores e o número de tentativas de cada jogador.
Ela armazena os melhores rankings em um array <code>ranking[]</code> e os nomes dos jogadores em um array bidimensional <code>nomes[][]</code>.
Os rankings são determinados com base no menor número de tentativas. Portanto, quanto menor o número de tentativas, melhor o ranking.
A função exibe os melhores rankings na tela, mostrando o nome do jogador e o número de tentativas para acertar o número secreto.</li>
        <li>A função <code>humano()</code> é responsável pela jogada do usuário. Ela solicita ao usuário a posição desejada e faz a jogada, desde que a posição esteja vazia.</li>
        <li>A função <code>limparRanking()</code>:

Essa função é responsável por limpar o conteúdo do arquivo "ranking.txt", apagando todos os dados armazenados nele.
Ela abre o arquivo "ranking.txt" no modo de escrita w e fecha imediatamente o arquivo, o que faz com que o conteúdo existente seja excluído.</li>
    </ul>
    <p>A função <code>main()</code>:

Essa é a função principal do programa.
Ela exibe o menu para o jogador e solicita que o jogador escolha uma opção.
Com base na opção escolhida pelo jogador, a função chama a função correspondente.
O loop <code>do-while</code> permite que o jogador selecione várias opções até escolher a opção para sair do jogo.</p>
