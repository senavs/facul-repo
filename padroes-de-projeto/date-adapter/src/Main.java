public class Main {

    public static void main(String[] args) {
        int dia = 24;
        int mes = 4;
        int ano = 2020;

        Date data = new BrazilianDate(dia, mes, ano);
        System.out.println(data);

        data = new AmericanDate(ano, mes, dia);
        System.out.println(data);
    }
}
