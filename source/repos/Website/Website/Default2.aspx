<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="idorder" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="idorder" HeaderText="idorder" ReadOnly="True" SortExpression="idorder" />
                <asp:BoundField DataField="ordernum" HeaderText="ordernum" SortExpression="ordernum" />
                <asp:BoundField DataField="ordercol" HeaderText="ordercol" SortExpression="ordercol" />
                <asp:BoundField DataField="idperson" HeaderText="idperson" SortExpression="idperson" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:testConnectionString %>" ProviderName="<%$ ConnectionStrings:testConnectionString.ProviderName %>" SelectCommand="SELECT `order`.* FROM `order`"></asp:SqlDataSource>
        <div>
        </div>
    </form>
</body>
</html>
