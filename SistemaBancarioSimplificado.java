
public class SistemaBancarioSimplificado {
	public static void main(String[] args) {
		ContaBancaria conta1 = new ContaBancaria(1, "João", 1000.0);
		ContaBancaria conta2 = new ContaBancaria(2,"Maria", 10000);
		
		System.out.println(conta1.obterSaldo());
		
		System.out.println(conta1.realizarDeposito(200.0));
	    System.out.println(conta1.realizarSaque(150.0));
	    
	    System.out.println(conta2.obterSaldo());
	    
	    System.out.println(conta2.realizarSaque(50000)); 
	    System.out.println(conta2.realizarDeposito(150));
	    
	    System.out.println(conta2.realizarSaque(100));
	    
	}

}
