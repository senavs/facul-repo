<%@ page import="crud.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>User - list</title>
	</head>
	<body>
		<% User[] users = (User[]) request.getAttribute("users"); %>
		
		<% for (User user: users) {%>
			<% if (user != null) {%>
				<p><%= user.getEmail()%> - <%= user.getPassword() %> - <%= user.getBirthday() %></p>
				<hr>
			<%}%>
		<%}%>
	</body>
</html>