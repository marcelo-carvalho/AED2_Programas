/**
 * Geracao de elementos de um array
 * @author Max do Val Machado
 * @version 3 08/2020
 */

import java.util.*;

class Geracao {
   protected int[] array;
   protected int n;


	/**
	 * Construtor.
	 */
   public Geracao(){
      array = new int[100];
      n = array.length;
   }


	/**
	 * Construtor.
	 * @param int tamanho do array de numeros inteiros.
	 */
   public Geracao(int tamanho){
      array = new int[tamanho];
      n = array.length;
   }


	/**
	 * Produz um array ordenado de modo crescente.
	 */
	public void crescente() {
		for (int i = 0; i < n; i++) {
			array[i] = i;
		}
	}


	/**
	 * Produz um array ordenado de modo decrescente.
	 */
	public void decrescente() {
		for (int i = 0; i < n; i++) {
			array[i] = n - 1 - i;
		}
	}


	/**
	 * Produz um array com numeros aleatorios.
	 */
	public void aleatorio() {
		Random rand = new Random();
	   crescente();	
		for (int i = 0; i < n; i++) {
         swap(i, Math.abs(rand.nextInt()) % n);
		}
	}


	/**
	 * Efetua a leitura dos elementos via entrada padrao.
	 */
	public void entradaPadrao() {
      n = MyIO.readInt();
      array = new int[n];

		for (int i = 0; i < n; i++) {
			array[i] = MyIO.readInt();
		}
	}