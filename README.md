<!-----



Conversion time: 2.046 seconds.


Using this Markdown file:

1. Paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β35
* Mon Apr 08 2024 21:21:57 GMT-0700 (PDT)
* Source doc: Relatório INF05016 Dijkstra KHeap Algoritmos Avançados
* Tables are currently converted to HTML tables.
----->


<p style="text-align: right">
08/04/2024</p>



# Relatório INF05016:

Augusto Falcão Flach



1. Possíveis detalhes relevantes da implementação:

Não sou um bom programador C++, mas estou tentando aprender, então resolvi tentar usar a linguagem. Isso talvez fique evidente se olhar o código. Então apesar de a complexidade assintótica continuar correta, acredito que o programa ficou drasticamente mais lento devido a alguma falta de habilidade pontual (e à minha necessidade de ter ponteiros para todos os lados).

Eu rodei o algoritmo nos Estados Unidos partindo do vértice 1 ao 2 com os 2,3,4,5,10-Heap para testar qual seria mais rápido. O que venceu foi o 4-Heap. A partir disso, usei ele para os outros testes.

O 10-Heap foi o mais lento, apesar de ter sido o que necessitou de menos iterações de SiftUp e SiftDown. Acredito que isso se deve a “precisar” fazer a comparação entre o valor de todos os filhos de um nó para escolher o menor. Dessa forma, por exemplo, K comparações para cada Sift Down => 10*82330664 > 2 * 224355914. Então apesar de ter menos Sift Downs, possui mais comparações (para esse grafo e vértices escolhidos).



2. O ambiente de teste:

	Rodei os testes em um notebook Ninkear com 16GB DDR4 (2666GHz) - i7-1165G7 @ 2.80GHz - SSD NVMe 512GB (3000Mb/s) rodando Kubuntu 23.10. O compilador pode até importar, mas entendo pouco disso. Rodei os testes pela IDE CLion (JetBrains), diretamente pelo console da IDE (em modo Debug, o que provavelmente é mais lento).




###
    c-d) O resultado dos experimentos e análise:

	**_NOTA: Recomendo ver os resultados pelo PDF por mais fácil visualização. Fiz no Google Sheets e o .csv ficou sem a formatação._**



	Grafo nos Estados Unidos:


<table>
  <tr>
   <td><strong>Nodes 1 -> 2</strong>
   </td>
   <td><strong>Inserts</strong>
   </td>
   <td><strong>DeleteMins</strong>
   </td>
   <td><strong>Updates</strong>
   </td>
   <td><strong>SiftUp (iterations)</strong>
   </td>
   <td><strong>SiftDown (iterations)</strong>
   </td>
   <td><strong>Duration</strong>
   </td>
  </tr>
  <tr>
   <td>10-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1712835</p>

   </td>
   <td><p style="text-align: right">
1203067</p>

   </td>
   <td><p style="text-align: right">
82330664</p>

   </td>
   <td>80880ms
   </td>
  </tr>
  <tr>
   <td>5-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1712871</p>

   </td>
   <td><p style="text-align: right">
2150936</p>

   </td>
   <td><p style="text-align: right">
108893981</p>

   </td>
   <td>72396ms
   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1712828</p>

   </td>
   <td><p style="text-align: right">
2667524</p>

   </td>
   <td><p style="text-align: right">
124658356</p>

   </td>
   <td>67212ms
   </td>
  </tr>
  <tr>
   <td>3-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1712869</p>

   </td>
   <td><p style="text-align: right">
3679047</p>

   </td>
   <td><p style="text-align: right">
150927286</p>

   </td>
   <td>70406ms
   </td>
  </tr>
  <tr>
   <td>2-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1712809</p>

   </td>
   <td><p style="text-align: right">
6788424</p>

   </td>
   <td><p style="text-align: right">
224355914</p>

   </td>
   <td>74184ms
   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>30-Iterations average</strong>
   </td>
   <td><strong>Inserts</strong>
   </td>
   <td><strong>DeleteMins</strong>
   </td>
   <td><strong>Updates</strong>
   </td>
   <td><strong>SiftUp (iterations)</strong>
   </td>
   <td><strong>SiftDown (iterations)</strong>
   </td>
   <td><strong>Duration</strong>
   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
23947347</p>

   </td>
   <td><p style="text-align: right">
1717347</p>

   </td>
   <td><p style="text-align: right">
2694603</p>

   </td>
   <td><p style="text-align: right">
123436326</p>

   </td>
   <td>57383ms
   </td>
  </tr>
</table>


	Grafos gerados Aleatoriamente:


<table>
  <tr>
   <td><strong>20-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><p style="text-align: right">
<strong>Inserts</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>DeleteMins</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Updates</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftUp (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftDown (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Duration</strong></p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
30891</p>

   </td>
   <td><p style="text-align: right">
11984</p>

   </td>
   <td><p style="text-align: right">
25473</p>

   </td>
   <td><p style="text-align: right">
101ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.3 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
29508</p>

   </td>
   <td><p style="text-align: right">
11560</p>

   </td>
   <td><p style="text-align: right">
25554</p>

   </td>
   <td><p style="text-align: right">
77ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.2 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
27368</p>

   </td>
   <td><p style="text-align: right">
10662</p>

   </td>
   <td><p style="text-align: right">
25634</p>

   </td>
   <td><p style="text-align: right">
57ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.1 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
23959</p>

   </td>
   <td><p style="text-align: right">
9520</p>

   </td>
   <td><p style="text-align: right">
25684</p>

   </td>
   <td><p style="text-align: right">
39ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.05 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
20549</p>

   </td>
   <td><p style="text-align: right">
8437</p>

   </td>
   <td><p style="text-align: right">
25679</p>

   </td>
   <td><p style="text-align: right">
22ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
12496</p>

   </td>
   <td><p style="text-align: right">
6020</p>

   </td>
   <td><p style="text-align: right">
25669</p>

   </td>
   <td><p style="text-align: right">
14ms</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>20-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><p style="text-align: right">
<strong>Inserts</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>DeleteMins</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Updates</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftUp (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftDown (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Duration</strong></p>

   </td>
  </tr>
  <tr>
   <td>40000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
40001</p>

   </td>
   <td><p style="text-align: right">
40001</p>

   </td>
   <td><p style="text-align: right">
182824</p>

   </td>
   <td><p style="text-align: right">
73359</p>

   </td>
   <td><p style="text-align: right">
266133</p>

   </td>
   <td><p style="text-align: right">
346ms</p>

   </td>
  </tr>
  <tr>
   <td>20000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
20001</p>

   </td>
   <td><p style="text-align: right">
20001</p>

   </td>
   <td><p style="text-align: right">
77569</p>

   </td>
   <td><p style="text-align: right">
32382</p>

   </td>
   <td><p style="text-align: right">
122767</p>

   </td>
   <td><p style="text-align: right">
106ms</p>

   </td>
  </tr>
  <tr>
   <td>10000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
10001</p>

   </td>
   <td><p style="text-align: right">
10001</p>

   </td>
   <td><p style="text-align: right">
31882</p>

   </td>
   <td><p style="text-align: right">
14242</p>

   </td>
   <td><p style="text-align: right">
56471</p>

   </td>
   <td><p style="text-align: right">
43ms</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
5001</p>

   </td>
   <td><p style="text-align: right">
12496</p>

   </td>
   <td><p style="text-align: right">
6020</p>

   </td>
   <td><p style="text-align: right">
25669</p>

   </td>
   <td><p style="text-align: right">
14ms</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>50-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><p style="text-align: right">
<strong>Inserts</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>DeleteMins</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Updates</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftUp (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>SiftDown (iterations)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>Duration</strong></p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
11888</p>

   </td>
   <td><p style="text-align: right">
4710</p>

   </td>
   <td><p style="text-align: right">
8911</p>

   </td>
   <td><p style="text-align: right">
28ms</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
1000</p>

   </td>
   <td><p style="text-align: right">
1000</p>

   </td>
   <td><p style="text-align: right">
5270</p>

   </td>
   <td><p style="text-align: right">
2096</p>

   </td>
   <td><p style="text-align: right">
3999</p>

   </td>
   <td><p style="text-align: right">
7ms</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
11358</p>

   </td>
   <td><p style="text-align: right">
4433</p>

   </td>
   <td><p style="text-align: right">
8938</p>

   </td>
   <td><p style="text-align: right">
20ms</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
1001</p>

   </td>
   <td><p style="text-align: right">
1001</p>

   </td>
   <td><p style="text-align: right">
5009</p>

   </td>
   <td><p style="text-align: right">
2018</p>

   </td>
   <td><p style="text-align: right">
4011</p>

   </td>
   <td><p style="text-align: right">
6ms</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
2001</p>

   </td>
   <td><p style="text-align: right">
11358</p>

   </td>
   <td><p style="text-align: right">
4433</p>

   </td>
   <td><p style="text-align: right">
8938</p>

   </td>
   <td><p style="text-align: right">
20ms</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
1001</p>

   </td>
   <td><p style="text-align: right">
1001</p>

   </td>
   <td><p style="text-align: right">
4526</p>

   </td>
   <td><p style="text-align: right">
1836</p>

   </td>
   <td><p style="text-align: right">
4014</p>

   </td>
   <td><p style="text-align: right">
7ms</p>

   </td>
  </tr>
</table>


Também fiz outros testes para olhar como os tempos variam entre cada mudança de variável.  Por exemplo, tentei projetar o comportamento do algoritmo para um Edge Chance “semelhante” ao dos estados unidos (#arcs / #nodes) / #nodes = 1.01718995e-7. Como é de se imaginar, isso gerou um grafo quase totalmente desconexo, e todos testes geram “inf”. Comecei a conseguir uma taxa &lt; 50% de “inf” para EdgeChance > 0.0002.

Abaixo seguem os resultados calculados e a confirmação de que estão dentro dos limites teóricos.


<table>
  <tr>
   <td><strong>Nodes 1 -> 2 (US Graph)</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><strong><em>r</em></strong>
   </td>
   <td><strong><em>i</em></strong>
   </td>
   <td><strong><em>d</em></strong>
   </td>
   <td><strong><em>u</em></strong>
   </td>
   <td><strong><em>K</em></strong>
   </td>
  </tr>
  <tr>
   <td>10-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,228</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
10</p>

   </td>
  </tr>
  <tr>
   <td>5-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,212</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
5</p>

   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,209</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>3-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,202</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
3</p>

   </td>
  </tr>
  <tr>
   <td>2-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,190</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
2</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>30-Iterations Average (US Graph)</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><strong><em>r</em></strong>
   </td>
   <td><strong><em>i</em></strong>
   </td>
   <td><strong><em>d</em></strong>
   </td>
   <td><strong><em>u</em></strong>
   </td>
   <td><strong><em>K</em></strong>
   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
0,207</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,029</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>20-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><strong><em>r</em></strong>
   </td>
   <td><strong><em>i</em></strong>
   </td>
   <td><strong><em>d</em></strong>
   </td>
   <td><strong><em>u</em></strong>
   </td>
   <td><strong><em>K</em></strong>
   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
10.000.000</p>

   </td>
   <td><p style="text-align: right">
0,149</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,003</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.3 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
7.500.000</p>

   </td>
   <td><p style="text-align: right">
0,153</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,004</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.2 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
5.000.000</p>

   </td>
   <td><p style="text-align: right">
0,158</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,005</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.1 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
2.500.000</p>

   </td>
   <td><p style="text-align: right">
0,169</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,010</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.05 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
1.250.000</p>

   </td>
   <td><p style="text-align: right">
0,182</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,016</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
250.000</p>

   </td>
   <td><p style="text-align: right">
0,229</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,050</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>20-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><strong><em>r</em></strong>
   </td>
   <td><strong><em>i</em></strong>
   </td>
   <td><strong><em>d</em></strong>
   </td>
   <td><strong><em>u</em></strong>
   </td>
   <td><strong><em>K</em></strong>
   </td>
  </tr>
  <tr>
   <td>40000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
40.000</p>

   </td>
   <td><p style="text-align: right">
16.000.000</p>

   </td>
   <td><p style="text-align: right">
0,169</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,011</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>20000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
20.000</p>

   </td>
   <td><p style="text-align: right">
4.000.000</p>

   </td>
   <td><p style="text-align: right">
0,185</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,019</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>10000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
10.000</p>

   </td>
   <td><p style="text-align: right">
1.000.000</p>

   </td>
   <td><p style="text-align: right">
0,205</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,032</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
250.000</p>

   </td>
   <td><p style="text-align: right">
0,229</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,050</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>50-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><strong><em>r</em></strong>
   </td>
   <td><strong><em>i</em></strong>
   </td>
   <td><strong><em>d</em></strong>
   </td>
   <td><strong><em>u</em></strong>
   </td>
   <td><strong><em>K</em></strong>
   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
3.200.000</p>

   </td>
   <td><p style="text-align: right">
0,156</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,004</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
800.000</p>

   </td>
   <td><p style="text-align: right">
0,168</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,007</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
2.400.000</p>

   </td>
   <td><p style="text-align: right">
0,159</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,005</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
600.000</p>

   </td>
   <td><p style="text-align: right">
0,173</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,008</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
1.600.000</p>

   </td>
   <td><p style="text-align: right">
0,159</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,007</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
400.000</p>

   </td>
   <td><p style="text-align: right">
0,180</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
1</p>

   </td>
   <td><p style="text-align: right">
0,011</p>

   </td>
   <td><p style="text-align: right">
4</p>

   </td>
  </tr>
</table>


	Também fiz medições de tempo. Passei quase meio dia tentando fazer essas execuções, mas bem dificilmente elas tinham resultados consistentes. Boa parte do tempo empregado nas execuções não era rodando o algoritmo, mas sim gerando os grafos. Esse processo levava centenas de vezes mais tempo do que a execução do Dijkstra.

Mesmo rodando Dijkstra centenas de vezes, havia muita variação entre os resultados. Esses foram os conjuntos de dados mais consistentes que consegui:


<table>
  <tr>
   <td><strong>Nodes 1 -> 2 (US Graph)</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><p style="text-align: right">
<strong>Duration (ms)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>T/((n+m)log(n))</strong></p>

   </td>
  </tr>
  <tr>
   <td>10-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
80.880</p>

   </td>
   <td><p style="text-align: right">
0,0001332</p>

   </td>
  </tr>
  <tr>
   <td>5-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
72.396</p>

   </td>
   <td><p style="text-align: right">
0,0001192</p>

   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
67.212</p>

   </td>
   <td><p style="text-align: right">
0,0001107</p>

   </td>
  </tr>
  <tr>
   <td>3-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
70.406</p>

   </td>
   <td><p style="text-align: right">
0,0001160</p>

   </td>
  </tr>
  <tr>
   <td>2-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
74.184</p>

   </td>
   <td><p style="text-align: right">
0,0001222</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>40-Iterations Average (US Graph)</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><p style="text-align: right">
<strong>Duration (ms)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>T/((n+m)log(n))</strong></p>

   </td>
  </tr>
  <tr>
   <td>4-Heap
   </td>
   <td><p style="text-align: right">
23.947.347</p>

   </td>
   <td><p style="text-align: right">
58.333.344</p>

   </td>
   <td><p style="text-align: right">
57.383</p>

   </td>
   <td><p style="text-align: right">
0,0000945</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>20-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><p style="text-align: right">
<strong>Duration (ms)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>T/((n+m)log(n))</strong></p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
10.000.000</p>

   </td>
   <td><p style="text-align: right">
101</p>

   </td>
   <td><p style="text-align: right">
0,0000027</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.3 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
7.500.000</p>

   </td>
   <td><p style="text-align: right">
77</p>

   </td>
   <td><p style="text-align: right">
0,0000028</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.2 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
5.000.000</p>

   </td>
   <td><p style="text-align: right">
57</p>

   </td>
   <td><p style="text-align: right">
0,0000031</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.1 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
2.500.000</p>

   </td>
   <td><p style="text-align: right">
39</p>

   </td>
   <td><p style="text-align: right">
0,0000042</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.05 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
1.250.000</p>

   </td>
   <td><p style="text-align: right">
22</p>

   </td>
   <td><p style="text-align: right">
0,0000047</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
250.000</p>

   </td>
   <td><p style="text-align: right">
14</p>

   </td>
   <td><p style="text-align: right">
0,0000148</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>40-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><p style="text-align: right">
<strong>Duration (ms)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>T/((n+m)log(n))</strong></p>

   </td>
  </tr>
  <tr>
   <td>40000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
40.000</p>

   </td>
   <td><p style="text-align: right">
16.000.000</p>

   </td>
   <td><p style="text-align: right">
346</p>

   </td>
   <td><p style="text-align: right">
0,0000047</p>

   </td>
  </tr>
  <tr>
   <td>20000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
20.000</p>

   </td>
   <td><p style="text-align: right">
4.000.000</p>

   </td>
   <td><p style="text-align: right">
106</p>

   </td>
   <td><p style="text-align: right">
0,0000061</p>

   </td>
  </tr>
  <tr>
   <td>10000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
10.000</p>

   </td>
   <td><p style="text-align: right">
1.000.000</p>

   </td>
   <td><p style="text-align: right">
43</p>

   </td>
   <td><p style="text-align: right">
0,0000106</p>

   </td>
  </tr>
  <tr>
   <td>5000 Nodes - 0.01 Edge Chance
   </td>
   <td><p style="text-align: right">
5.000</p>

   </td>
   <td><p style="text-align: right">
250.000</p>

   </td>
   <td><p style="text-align: right">
14</p>

   </td>
   <td><p style="text-align: right">
0,0000148</p>

   </td>
  </tr>
  <tr>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td><strong>50-Iteractions Average (Random Graph) - 4-Heap</strong>
   </td>
   <td><strong><em>n</em></strong>
   </td>
   <td><strong><em>m</em></strong>
   </td>
   <td><p style="text-align: right">
<strong>Duration (ms)</strong></p>

   </td>
   <td><p style="text-align: right">
<strong>T/((n+m)log(n))</strong></p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
3.200.000</p>

   </td>
   <td><p style="text-align: right">
28</p>

   </td>
   <td><p style="text-align: right">
0,0000026</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.8 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
800.000</p>

   </td>
   <td><p style="text-align: right">
7</p>

   </td>
   <td><p style="text-align: right">
0,0000029</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
2.400.000</p>

   </td>
   <td><p style="text-align: right">
20</p>

   </td>
   <td><p style="text-align: right">
0,0000025</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.6 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
600.000</p>

   </td>
   <td><p style="text-align: right">
6</p>

   </td>
   <td><p style="text-align: right">
0,0000033</p>

   </td>
  </tr>
  <tr>
   <td>2000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
2.000</p>

   </td>
   <td><p style="text-align: right">
1.600.000</p>

   </td>
   <td><p style="text-align: right">
20</p>

   </td>
   <td><p style="text-align: right">
0,0000038</p>

   </td>
  </tr>
  <tr>
   <td>1000 Nodes - 0.4 Edge Chance
   </td>
   <td><p style="text-align: right">
1.000</p>

   </td>
   <td><p style="text-align: right">
400.000</p>

   </td>
   <td><p style="text-align: right">
7</p>

   </td>
   <td><p style="text-align: right">
0,0000058</p>

   </td>
  </tr>
</table>


	O último conjunto de dados foi o menos estruturado, então mesmo mostrando os mesmos resultados, têm uma pior visualização.

	Apesar disso, gostaria de apontar que o cálculo de **T/((n+m)log(n))** gerou valores consistentemente decrescentes. Não foram realizadas as contas para conferir se eles se aproximam corretamente de algum comportamento teórico, portanto deixaremos como trabalhos futuros calcular corretamente seu comportamento esperado e empírico para afirmar diretamente se os mesmos se aproximam de um comportamento 1/X ou de funções logarítmicas inversas.


### Conclusão

	Foi feita a construção de um algoritmo de Dijkstra e de uma fila de prioridade K-Heap na linguagem C++. A partir disso, foi feito o teste de processamento com base em diversas entradas de exemplo do desafio DIMACS 9, e por fim foi feita a execução do algoritmo com entradas geradas randomicamente para a constatação de seus comportamentos empíricos, e de que os mesmos respeitam os limites assintóticos teóricos.
