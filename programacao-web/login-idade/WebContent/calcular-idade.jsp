<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>Insert title here</title>
		<title>Verifica idade</title>
	</head>
	<body>
		<h1>Programa para verificar a idade.</h1>

		<form action="http://localhost:8080/login-idade/calcular">
			<fieldset>
				<legend>Dados pessoais:</legend>
				<p style="display: inline">Data de nascimento:</p>
				<input type="text" name="data_nascimento" /> <input type="submit" value="Verificar" />
			</fieldset>
		</form>
	</body>
</html>