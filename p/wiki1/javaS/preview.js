$(document).ready(function(){
	// alert("jajnjkdc kaj vcfdalk") ;
$.ajax({
        type: "GET",
        url : "https://en.wikipedia.org//w/api.php?action=query&format=json&prop=extracts&titles=Programming_paradigm&utf8=1&ascii=1&exintro=1&explaintext=1&callback=?",
        contentType: "application/json; charset=utf-8",
        async: true,
        dataType : "json" ,
        success: function(data , textStatus, jqXHR){
          console.log(data);
          
          var len = data[1].length;
          //alert(len);
          // alert(data[3][2]) ;
      
          

        }
        
       
      })

// alert(link) ;

});