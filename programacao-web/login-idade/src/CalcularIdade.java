import java.io.IOException;
import java.io.PrintWriter;
import java.time.LocalDateTime;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/calcular")
public class CalcularIdade extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public CalcularIdade() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter htmlWriter = response.getWriter();
		
		// getting date
		String[] dateReceived = request.getParameter("data_nascimento").replace(" ", "/").replace("-", "/").split("/");

		try {
			// validating date
			Date birth = new Date(Integer.parseInt(dateReceived[0]), Integer.parseInt(dateReceived[1]), Integer.parseInt(dateReceived[2]));
			
			// getting today date
			LocalDateTime now = LocalDateTime.now();
			Date today = new Date(now.getDayOfMonth(), now.getMonthValue(), now.getYear());
			
			// getting age
			int age = Age.calculate(today, birth);
			htmlWriter.println("Data de hoje: " + today + "\nData enviada: "+ birth + "\nIdade: " + age);
		} catch (IllegalArgumentException e) {
			htmlWriter.println("Data enviada não é válida.");
		} catch (ArrayIndexOutOfBoundsException e) {
			htmlWriter.println("Data enviada não está completa. Tente dd/mm/yyyy");
		} catch (RuntimeException e) {
			htmlWriter.println("Impossível calcular idade com data de nascimento futura.");
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
