import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/valida-usuario")
public class ValidaUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static String USUARIO = "admin";
	private static String SENHA = "123";
       
    public ValidaUsuario() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String new_usuario = request.getParameter("usuario");
		String new_senha = request.getParameter("senha");
		
		HttpSession session = request.getSession();
		session.setAttribute("logado", true);
		
		
		if (USUARIO.equals(new_usuario) && SENHA.equals(new_senha)) {
			response.sendRedirect("calcular-idade.jsp");
		} else {
			request.setAttribute("msg-erro", "Usuário ou Senha incorretos");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
		}
		
	}

}
