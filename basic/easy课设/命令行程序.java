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
		System.out.println("首先进行登录，请您输入工号");
        String str = sc.nextLine();
        String real="0";
        String password ="123456";
		String sql="select * from 权限 where 账户="+str;
		ResultSet rs=state.executeQuery(sql); 
		while(rs.next()){ 
			real=rs.getString(3);
			password=rs.getString(2);}
			System.out.println("请输入密码：");
			String pass = sc.nextLine();
			if(pass.equals(password)) 
				{if(real.equals("1"))
					addel();
				else
					lookforwage(str);}
			else return;
		connection.close();
	}

	public static void lookforwage(String str) throws SQLException{//通过视图实现
		String sql=" SELECT   *    FROM   syscolumns    WHERE   id   in(   SELECT   id    FROM   sysobjects    WHERE   (name   =   '基本'))";
		ResultSet rs=state.executeQuery(sql);
		while(rs.next()){
		    System.out.print(rs.getString(1)+"\t");
		    }
		System.out.println("");
		sql="Select * from 基本 where 员工编号="+str;
		rs=state.executeQuery(sql);
		while(rs.next()){
		    System.out.println(rs.getString(1)+"\t"+rs.getString(2)+"\t"+rs.getString(3));
		    }
	}
	
	public static void addel() throws SQLException{//管理员页面
		Scanner sc = new Scanner(System.in);;
		String sql;
		ResultSet rs;
		String str;
		while(true) {
			System.out.println("您要执行的操作\n1、报表 2、数据转储 3、操作表");
			str = sc.nextLine();
			if(str.equals("1"))
				print();
			if(str.equals("2"))
				store();
			if(str.equals("3")) {
			System.out.println("请选择要操作的数据库表");
	        table = sc.nextLine();
			sql=" SELECT   *    FROM   syscolumns    WHERE   id   in(   SELECT   id    FROM   sysobjects    WHERE   (name   =   '"+table+"'))";
			rs=state.executeQuery(sql);
			System.out.println("本表字段如下：");
			while(rs.next()){
			    System.out.print(rs.getString(1)+" ");
			    }
			System.out.println("");
			System.out.println("请问要实现那个功能？\n1.增加表数据\t2.删除表数据\t3.修改表数据\t4.查询表数据");
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
		System.out.println("请在对应字段填入对应值");
		int cont=1;
		String sql = null;
		String[] s=new String[15];
		Scanner sc = new Scanner(System.in);
		if(table.equals("岗位变更"))
		{
			s[1]=sc.nextLine();
			s[2]=sc.nextLine();
			s[3]=sc.nextLine();
			s[4]=sc.nextLine();
			s[5]=sc.nextLine();
			sql="insert into "+table+" values ("+s[1]+",'"+s[2]+"','"+s[3]+"','"+s[4]+"','"+s[5]+"')";}
		if(table.equals("奖惩"))
		{
			s[1]=sc.nextLine();
			s[2]=sc.nextLine();
			s[3]=sc.nextLine();
			s[4]=sc.nextLine();
			s[5]=sc.nextLine();
			sql="insert into "+table+" values ("+s[1]+",'"+s[2]+"','"+s[3]+"','"+s[4]+"','"+s[5]+"')";}
//		if(table.equals("员工"))
//			String sql="insert into "+table+" values ("+sc.nextLine()+",'"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"','"+sc.nextLine()+"')";
		//System.out.println(sql);}
		state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("操作完成");
		}
	}
	
	public static void del() throws SQLException//触发器保护
	{
		try{
		System.out.println("请问要删除条件的字段,如若想自定义删除方式可直接选1");
		Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String sql;
        String real="0";
        if(str.equals("1"))
        	sql=sc.nextLine();
        else
        {
        System.out.println("请问要删除条件字段的值");
        real = sc.nextLine();
        try{
		sql="delete from "+table+" where "+str+"='"+real+"'";}
        catch (Exception e) {
        	sql="delete from "+table+" where "+str+"="+real+"";
        }
        }
		state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("操作完成");
		}
	}
	
	public static void upd() throws SQLException
	{
		try{
		System.out.println("请问要修改条件的字段,如若想自定义删除方式可直接选1");
		Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String sql;
        String real="0";
        if(str.equals("1"))
        	sql=sc.nextLine();
        else
        {
        System.out.println("请问要修改条件字段的值");
        real = sc.nextLine();
        System.out.println("请问要修改字段的新值");
        String new_line = sc.nextLine();
        try{
		sql="update "+table+" set "+str+"= '"+new_line+"' where "+str+" = '"+real+"'";}
        catch (Exception e) {
		sql="update "+table+" set "+str+"= "+new_line+" where "+str+" = "+real+"";}
		System.out.println(sql);}
		ResultSet rs=state.executeQuery(sql); }
		catch (Exception e) {
			System.out.println("操作完成");
		}

	}
	
	public static void qua() throws SQLException
	{
		String sql="select * from "+table;
		ResultSet rs=state.executeQuery(sql); 
		while(rs.next()){
			if(table.equals("岗位变更"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			if(table.equals("奖惩"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5));
			if(table.equals("员工"))
				System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getString(4)+" "+rs.getString(5)+" "+rs.getString(6)+" "+rs.getString(7)+" "+rs.getString(8)+" "+rs.getString(9)+" "+rs.getString(10)+" "+rs.getString(11));
		    }
	}
	
	public static void print() throws SQLException//通过存储过程实现
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("要打印那个表？？");
        String table = sc.nextLine();
        String sql;
		sql="exec savedevidebyname "+table;
		ResultSet rs=state.executeQuery(sql); 
		System.out.println("打印完成！！请到H盘查看");
	}
	public static void store() throws SQLException//数据库备份恢复语句
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("1、保存数据库 2、从数据库中恢复");
        String str = sc.nextLine();
		if(str.equals("1")) {
			String sql="backup database wagemanage to disk='H:/Test.bak'";
			try{state.executeQuery(sql);}
			catch(Exception e) {;}}
		if(str.equals("2")) {
			String sql="restore database test from disk='H:/Test.bak'";
			try{state.executeQuery(sql); }
			catch(Exception e) {;}}
		System.out.println("操作完成");
	}
	
	
	public static void conncetDB() throws SQLException{//连接数据库
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			String url = "jdbc:sqlserver://localhost:1433;databaseName=wagemanage";
			connection = DriverManager.getConnection(url, "sa", "1");
			state=connection.createStatement();
		} catch (Exception e) {
			System.out.println("数据库连接失败");
			e.printStackTrace();
		}
	}
	
}