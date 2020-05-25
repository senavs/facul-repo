import java.io.IOException;
import java.time.LocalDateTime;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/calcular")
public class CalcularIdade extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public CalcularIdade() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession session = request.getSession();
		Boolean logado = (Boolean) session.getAttribute("logado");
		
		if (!logado) {
			request.setAttribute("msg-erro", "Logue para calcular a idade");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
		}
			
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
			
			request.setAttribute("today", today);
			request.setAttribute("birth", birth);
			request.setAttribute("age", age);
			request.getRequestDispatcher("resultado.jsp").forward(request, response);
		} catch (IllegalArgumentException e) {
			request.setAttribute("msg-erro", "Data enviada não é válida.");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
		} catch (ArrayIndexOutOfBoundsException e) {
			request.setAttribute("msg-erro", "Data enviada não está completa. Tente dd/mm/yyyy.");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
		} catch (RuntimeException e) {
			request.setAttribute("msg-erro", "Impossível calcular idade com data de nascimento futura.");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
		}
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
