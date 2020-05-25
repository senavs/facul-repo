<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
		<title>Login</title>
		<meta charset="utf-8">
	</head>
	<body>
		<div style="text-align: center;">
			<fieldset style="display: inline;">
				<h3>Calcula Idade + Valida Data</h3>
				<form action="http://localhost:8080/login-idade/valida-usuario">
					<label for="usuario">USUÁRIO</label>
					<input type="text" id="usuario" name="usuario" required>
					<br><br>
					<label for="senha">SENHA</label>
					<input type="password" id="senha" name="senha" required>
					<br><br>
					<input type="submit" value="Entrar">
				</form>		
			</fieldset>
		</div>
	</body>
</html>