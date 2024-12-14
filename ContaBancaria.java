    public class ContaBancaria {
    private int numeroConta;
    private String nomeTitular;
    private double saldo;

    public ContaBancaria(int numeroConta, String nomeTitular, double saldoInicial) {
        this.numeroConta = numeroConta;
        this.nomeTitular = nomeTitular;
        this.saldo = saldoInicial;
    }

    public String realizarDeposito(double valorDeposito) {
        saldo += valorDeposito;
        return "Depósito de R$" + valorDeposito + " realizado. Saldo atual: R$" + saldo;
    }

    public String realizarSaque(double valorSaque) {
        if (valorSaque <= saldo) {
            saldo -= valorSaque;
            return "Saque de R$" + valorSaque + " realizado. Saldo atual: R$" + saldo;
        } else {
            return "Saldo insuficiente para realizar o saque.";
        }
    }

    public String obterSaldo() {
        return "Saldo atual da conta: R$" + saldo;
    }
}
