# Shortest Path
 Este projeto tem como objetivo mostrar o menor caminho entre dois pontos, aplicando isso numa situação de emergência.

## Descrição do projeto:
A ideia geral é o usuario digitar o local da emergência e o programa irá mostrar o local da ambulancia mais próxima, 
o caminho que irá fazer ate o destino e o tempo aproximado que irá demorar pra chegar, considerando a velocidadde média da ambulância.
Para isso, foi necessário criar dois arquivos, o primeiro (mapa.txt) contém varios bairros, incluindo a distancia entre os bairros vizinhos. O segundo (garagem_ambulancias.txt), tem os locais onde estão as ambulâncias.
## Implementação:
Para a implementação do grafo foi feita utilizando lista encadeada para armazenar os dados dos bairros, e também foi utilizada uma lista encadeada para armazenar os locais de ambulancia.
Em seguida, foi implementado o algoritmo de Dijkstra para organizar os bairros a partir de uma fonte, de maneira que se tenha o menor da caminho dessa fonte, até o destino desejado.
Por fim, era necessário imprimir o caminho da ambulância mais próxima do local da emergência digitado pelo usuário. Para isso, a partir do uso do Dijkstra, encontrou-se o local da ambulância mais próxima, e em seguida, foi calculada a menor distância entre a ambulância e o local da emergência, mostrando o caminho pelo qual a ambulância deveria passar.
### Exemplo de uso:
Inicialmente irá aparecer na tela uma menu para o usuário decidir o que ele irá fazer: sair do programa ou solicitar uma ambulância. No caso da escolha deste ultimo o usuário de verá digitar um bairro de florianópolis (que cotenha no lista) da seguinte maneira:
          ```
          Monte Verde
          ```       Com o inicial maiúscula.
Para este exemplo, o caminho feito pela ambulância será: 
        ```
        
        Centro
        
        Trindade
        
        Joao Paulo
        
        Monte Verde
        ```
        
## Contribuição
* **Heloiza Martins**: Menu(main), ler arquivo de ambulâncias e de bairros, imprimir caminho versão final, libera_grafo.

* **Suzi Yousif**: Dijkstra, ler arquivo de ambulâncias e de bairros, imprimir caminho versão inicial, cria_local, libera_local_ambulâncias.
