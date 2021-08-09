// JavaScript Document
var Dianji=0;
window.onload=function(){
	var buhao = document.getElementById("buhao");
	var hao = document.getElementById("hao");
	buhao.onclick=function(){
		Dianji++;
		if(Dianji==1){
	   			alert("小姐姐再考虑一下呗");
	   }else if(Dianji==2){
		   		alert("我是你见过的最帅气善良可爱的男孩");
		   		
	   }else if(Dianji==3){
		   		alert("一生一世爱你");
		   		
	   }else if(Dianji==4){
		   		alert("家务我全干");
		   		
	  }else if(Dianji==5){
		   		alert("不藏私房钱");
	  }else if(Dianji==6){
		   		alert("我可是有房的人了");
	  }else if(Dianji==7){
		   		alert("你信不信我让你关不掉");
		  		Dianji=1;
	  }

	}
	hao.onclick=function(){
		alert("小姐姐终于同意了，我爱你");
	}
	

}
