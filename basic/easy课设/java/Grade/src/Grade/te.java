package Grade;
import java.sql.*;
import java.util.Scanner;
public class te {
	public static Connection connection ;
	public static Statement state;
	public static String table;
	public static void main(String[] args) throws SQLException {
		conncetDB(); 
		Scanner sc = new Scanner(System.in);
		System.out.println("���Ƚ��е�¼���������빤��");
        String str = sc.nextLine();
        String real="0";
        String password ="123456";
		String sql="select * from Ȩ�� where �˻�="+str;
		ResultSet rs=state.executeQuery(sql); 
		while(rs.next()){ 
			real=rs.getString(3);
			password=rs.getString(2);}
			System.out.println("���������룺");
			String pass = sc.nextLine();
			if(pass.equals(password)) 
				if(real.equals("1"))
				addel();
			else
				lookforwage(str);
		connection.close();
	}

	public static void lookforwage(String str) throws SQLException{//ͨ����ͼʵ��
		String sql=" SELECT   *    FROM   syscolumns    WHERE   id   in(   SELECT   id    FROM   sysobjects    WHERE   (name   =   '����'))";
		ResultSet rs=state.executeQuery(sql);
		while(rs.next()){
		    System.out.print(rs.getString(1)+"\t");
		    }
		System.out.println("");
		sql="Select * from ���� where Ա�����="+str;
		rs=state.executeQuery(sql);
		while(rs.next()){
		    System.out.println(rs.getString(1)+"\t"+rs.getString(2)+"\t"+rs.getString(3));
		    }
	}
	
	public static void addel() throws SQLException{//����Աҳ��
		Scanner sc = new Scanner(System.in);;
		String sql;
		ResultSet rs;
		String str;
		while(true) {
			System.out.println("��Ҫִ�еĲ���\n1������ 2������ת�� 3��������");
			str = sc.nextLine();
			if(str.equals("1"))
				print();
			if(str.equals("2"))
				store();
			if(str.equals("3")) {
			System.out.println("��ѡ��Ҫ���������ݿ��");
	        table = sc.nextLine();
			sql=" SELECT   *    FROM   syscolumns    WHERE   id   in(   SELECT   id    FROM   sysobjects    WHERE   (name   =   '"+table+"'))";
			rs=state.executeQuery(sql);
			System.out.println("�����ֶ����£�");
			while(rs.next()){
			    System.out.print(rs.getString(1)+" ");
			    }
			System.out.println("");
			System.out.println("����Ҫʵ���Ǹ����ܣ�\n1.���ӱ�����\t2.ɾ��������\t3.�޸ı�����\t4.��ѯ������");
			str = sc.nextLine();
		if(str.equals("1"))
			add();
		if(str.equals("2"))
			del();
		if(str.equals("3"))
			upd();
		if(str.equals("4"))
			qua();
		}
		}
	}
	public static void add() throws SQLException
	{
		try{
		System.out.println("���ڶ�Ӧ�ֶ������Ӧֵ");
		int cont=1;
		String[] s=new String[15];
		Scanner sc = new Scanner(System.in);
		if(table.equals("��λ���"))
			String sql="insert into "+table+" values ("+sc.nextLine()+","+sc.nextLine()+",'"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"')";
		if(table.equals("����"))
			String sql="insert into "+table+" values ("+sc.nextLine()+",'"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"')";
		if(table.equals("Ա��"))
			String sql="insert into "+table+" values ("+sc.nextLine()+",'"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"')";
		System.out.println(sql);
		ResultSet rs=state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("�������");
		}
	}
	
	public static void del() throws SQLException//����������
	{
		try{
		System.out.println("����Ҫɾ���������ֶ�,�������Զ���ɾ����ʽ��ֱ��ѡ1");
		Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String sql;
        String real="0";
        if(str.equals("1"))
        	sql=sc.nextLine();
        else
        {
        System.out.println("����Ҫɾ�������ֶε�ֵ");
        real = sc.nextLine();
        try{
		sql="delete from "+table+" where "+str+"='"+real+"'";}
        catch (Exception e) {
        	sql="delete from "+table+" where "+str+"="+real+"";
        }
        }
		state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("�������");
		}
	}
	
	public static void upd() throws SQLException
	{
		try{
		System.out.println("����Ҫ�޸��������ֶ�,�������Զ���ɾ����ʽ��ֱ��ѡ1");
		Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String sql;
        String real="0";
        if(str.equals("1"))
        	sql=sc.nextLine();
        else
        {
        System.out.println("����Ҫ�޸������ֶε�ֵ");
        real = sc.nextLine();
        System.out.println("����Ҫ�޸��ֶε���ֵ");
        String new_line = sc.nextLine();
        try{
		sql="update "+table+" set "+str+"= '"+new_line+"' where "+str+" = '"+real+"'";}
        catch (Exception e) {
		sql="update "+table+" set "+str+"= "+new_line+" where "+str+" = "+real+"";}
		System.out.println(sql);}
		ResultSet rs=state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("�������");
		}

	}
	
	public static void qua() throws SQLException
	{
		String sql="select * from "+table;
		ResultSet rs=state.executeQuery(sql); 
		while(rs.next()){
			if(table.equals("��λ���"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			if(table.equals("����"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			if(table.equals("Ա��"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5)+" "+rs.getString(6)+" "+rs.getString(7)+" "+rs.getString(8)+" "+rs.getString(9)+" "+rs.getString(10)+" "+rs.getString(11));
		    }
	}
	
	public static void print() throws SQLException//ͨ���洢����ʵ��
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Ҫ��ӡ�Ǹ�����");
        String table = sc.nextLine();
        String sql;
		sql="exec savedevidebyname "+table;
		ResultSet rs=state.executeQuery(sql); 
		System.out.println("��ӡ��ɣ����뵽H�̲鿴");
	}
	public static void store() throws SQLException//���ݿⱸ�ݻָ����
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("1���������ݿ� 2�������ݿ��лָ�");
        String str = sc.nextLine();
		if(str.equals("1")) {
			String sql="backup database wagemanage to disk='H:/Test.bak'";
			try{state.executeQuery(sql);}
			catch(Exception e) {;}}
		if(str.equals("2")) {
			String sql="restore database test from disk='H:/Test.bak'";
			try{state.executeQuery(sql); }
			catch(Exception e) {;}}
		System.out.println("�������");
	}
	
	
	public static void conncetDB() throws SQLException{//�������ݿ�
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			String url = "jdbc:sqlserver://localhost:1433;databaseName=wagemanage";
			connection = DriverManager.getConnection(url, "sa", "1");
			state=connection.createStatement();
		} catch (Exception e) {
			System.out.println("���ݿ�����ʧ��");
			e.printStackTrace();
		}
	}
	
}