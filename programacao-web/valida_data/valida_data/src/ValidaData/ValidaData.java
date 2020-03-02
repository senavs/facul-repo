package ValidaData;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/verifica_idade")
public class ValidaData extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public ValidaData() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		doGet(request, response);
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		PrintWriter html_output = response.getWriter();

		String data = request.getParameter("data_nascimento").replace("-", "/");
		SimpleDateFormat format = new SimpleDateFormat("yyyy/MM/dd");

		try {
			Date data_recebida = format.parse(data);
			Calendar data_nascimento = Calendar.getInstance();
			data_nascimento.setTime(data_recebida);

			Calendar data_hoje = Calendar.getInstance();

			Integer idade = data_hoje.get(Calendar.YEAR) - data_nascimento.get(Calendar.YEAR);

			if (data_hoje.get(Calendar.MONTH) < data_nascimento.get(Calendar.MONTH)) {
				idade--;
			} else if (data_hoje.get(Calendar.DAY_OF_MONTH) < data_nascimento.get(Calendar.DAY_OF_MONTH)) {
				idade--;
			} 
			

			html_output.println("<html><body>");
			html_output.println("<h1>Programa para verificar a idade.</h1>");
			html_output.println("<fieldset>");
			html_output.println("<legend>Dados pessoais:</legend>");
			html_output.println("<p>Data de nascimento: " + data + "</p>");
			html_output.println("<p>Idade: " + idade + "</p>");
			html_output.println("</fieldset>");
			html_output.println("</body></html>");

		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		// response.getWriter().append("Served at: ").append(request.getParameter("data_nascimento"));
	}

}
