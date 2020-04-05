from tkinter import *
from tkinter import messagebox

# Menu --------------------------------------------------

class Menu(object):
    def __init__(self, master):
        # Registro
        self.registro = Registro()
        
        # App
        master.title('Registro de aluno')
        master.geometry(f'+{round(master.winfo_screenwidth() * 0.1)}+{round(master.winfo_screenheight() * 0.1)}')
        self.app = Frame(master)
        self.app.grid()
        
        # Button Inserir Aluno
        self.bt_inserir = Button(self.app, text='Inserir Aluno', width=25, command=self.inserir_aluno)
        self.bt_inserir.grid(row=0, column=0, padx=2, pady=2)
        
        # Button Excluir Aluno
        self.bt_excluir = Button(self.app, text='Excluir Aluno', width=25, command=self.excluir_aluno)
        self.bt_excluir.grid(row=1, column=0, padx=2, pady=2)
        
        # Button Mostrar Alunos
        self.bt_mostrar = Button(self.app, text='Mostrar Alunos', width=25, command=self.mostrar_alunos)
        self.bt_mostrar.grid(row=2, column=0, padx=2, pady=2)
        
        # Encerrar Programa
        self.bt_encerrar = Button(self.app, text='Encerrar Programa', width=25, command=self.encerrar_programa)
        self.bt_encerrar.grid(row=3, column=0, padx=2, pady=2)
        
    def inserir_aluno(self):
        a = MenuInserir(self.app, self.registro)
    
    def excluir_aluno(self):
        a = MenuExcluir(self.app, self.registro)
    
    def mostrar_alunos(self):
        a = MenuMostrar(self.app, self.registro)
        
    def encerrar_programa(self):
        encerrar = messagebox.askyesno('Encerrar', 'Deseja finalizar o programa?\nTodos os dados serão excluídos do registro.')
        if encerrar:
            self.app.destroy()
            exit()

# Menu Inserir --------------------------------------------------

class MenuInserir(object):
    def __init__(self, master, registro):       
        # App
        self.app = Toplevel(master)
        self.app.title('Inserir Aluno')
        self.app.geometry(f'+{round(master.winfo_screenwidth() * 0.2)}+{round(master.winfo_screenheight() * 0.2)}')
        self.app.grid()
        
        # Matricula
        self.lb_matricula = Label(self.app, text='Matrícula:')
        self.lb_matricula.grid(row=0, column=0, sticky='E')
        self.et_matricula = Entry(self.app, width=25)
        self.et_matricula.grid(row=0, column=1)
        
        # Nome
        self.lb_nome = Label(self.app, text='Nome:')
        self.lb_nome.grid(row=1, column=0, sticky='E')
        self.et_nome = Entry(self.app, width=25)
        self.et_nome.grid(row=1, column=1)
        
        # Nota
        self.lb_nota = Label(self.app, text='Nota:')
        self.lb_nota.grid(row=2, column=0, sticky='E')
        self.et_nota = Entry(self.app, width=25)
        self.et_nota.grid(row=2, column=1)
        
        # Inserir
        self.bt_inserir = Button(self.app, text='Castrar', command=lambda: self.inserir_aluno(registro))
        self.bt_inserir.grid(row=3, column=0, sticky='WE', columnspan=2)
        
        master.wait_window(self.app)
        
    def inserir_aluno(self, registro):
        try:
            registro.insret(Aluno(self.et_matricula.get(), self.et_nome.get(), self.et_nota.get()))
        except Exception as err:
            print(err)
        else:
            messagebox.showinfo('Aluno', 'Aluno inserido com sucesso')
            self.et_matricula.delete(0, END)
            self.et_nome.delete(0, END)
            self.et_nota.delete(0, END)     

# Menu Excluir --------------------------------------------------

class MenuExcluir(object):
    def __init__(self, master, registro):       
        # App
        self.app = Toplevel(master)
        self.app.title('Excluir Aluno')
        self.app.geometry(f'+{round(master.winfo_screenwidth() * 0.2)}+{round(master.winfo_screenheight() * 0.2)}')
        self.app.grid()
        
        # Matricula
        self.lb_id = Label(self.app, text='ID Aluno:')
        self.lb_id.grid(row=0, column=0, sticky='E')
        self.et_id = Entry(self.app, width=15)
        self.et_id.grid(row=0, column=1)
        
        # Excluir
        self.bt_excluir = Button(self.app, text='Excluir', command=lambda: self.excluir_aluno(registro))
        self.bt_excluir.grid(row=3, column=0, sticky='WE', columnspan=2)
        
    def excluir_aluno(self, registro):
        try:
            excluiu = registro.delete(int(self.et_id.get()))
            if not excluiu:
                raise Exception
        except Exception as err:
            print(err)
        else:
            messagebox.showinfo('Aluno', 'Aluno excluido com sucesso')
            self.et_id.delete(0, END)

# Menu Mostrar --------------------------------------------------

class MenuMostrar(object):
    def __init__(self, master, registro):       
        # App
        self.app = Toplevel(master)
        self.app.title('Mostrar Alunos')
        self.app.geometry(f'+{round(master.winfo_screenwidth() * 0.2)}+{round(master.winfo_screenheight() * 0.2)}')
        self.app.grid()
        
        # Saida Mostrar
        self.tx_mostrar = Text(self.app, state=DISABLED, height=25, width=50)
        self.tx_mostrar.grid(row=3, column=0, sticky='WE', columnspan=2)
        
        self.mostrar_alunos(registro)
        
        
    def mostrar_alunos(self, registro):
        try:
            resultado = dict(registro.select())
        except Exception as err:
            print(err)
        else:
            self.tx_mostrar.config(state=NORMAL)
            if resultado == {}:
                self.tx_mostrar.insert(END, f'Nenhum aluno inserido.')
            for key in resultado.keys():
                self.tx_mostrar.insert(END, f'ID do Aluno: {key}' + '\n')
                self.tx_mostrar.insert(END, f'Matricula: {resultado[key]["matricula"]}' + '\n')
                self.tx_mostrar.insert(END, f'Nome: {resultado[key]["nome"]}'+ '\n')
                self.tx_mostrar.insert(END, f'Nota: {resultado[key]["nota"]}'+ '\n')
                self.tx_mostrar.insert(END, '\n\n')
            self.tx_mostrar.config(state=DISABLED)

# Aluno --------------------------------------------------

class Aluno(object):
    def __init__(self, matricula, nome, nota):
        self._matricula = matricula
        self._nome = nome
        self._nota = nota        

# Registro --------------------------------------------------

class Registro(object):
    def __init__(self):
        self._registro = dict()
        self._id_aluno = int(0)
    
    def insret(self, aluno):
        dados_aluno = dict()
        dados_aluno['matricula'] = aluno._matricula
        dados_aluno['nome'] = aluno._nome
        dados_aluno['nota'] = aluno._nota
        self._registro[self._id_aluno] = dados_aluno
        self._id_aluno += 1
        
        return True
    
    def delete(self, id_aluno):
        try:
            del self._registro[id_aluno]
        except KeyError:
            return False
        else:
            return True
    
    def select(self, id_aluno=None):
        if id_aluno is None:
            return self._registro
        else:
            try:
                self._registro[id_aluno]
            except KeyError:
                return False
            else:
                return self._registro[id_aluno]
            
# Executar --------------------------------------------------

if __name__ == '__main__':
    Menu(Tk())
    mainloop()