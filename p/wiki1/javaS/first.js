


$(document).ready(function(){
  function doClear(target){
    alert("function is called");
    $(target).val="";
  }

$("#after").hide();

$("#init-btn").click(function(){

  $("#init-btn").fadeOut("slow")
  $("#initial").fadeOut("slow" , function(){

    $("#after").show("slow") ;
  })
  $('body').css({'background-color':'#E65100'}) ;
})






















  
  $("#bar").keypress(function(e){
    if(e.which == '13'){
      var x = $("#bar").val() ;
  //alert(x);
    $("#result").html("<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><img src='images/load.gif'><h3>Fetching Data...</h3>")

    var arr = x.split(" ") ;
    var siz = arr.length ;
   
    for(var i = 0 ; i < siz ; i++)
    {
      arr[i] = encodeURIComponent(arr[i]) ;
    }




      var search = arr.join("+") ;

      console.log(search) ;
      
      $.ajax({
        type: "GET",
        url : "https://en.wikipedia.org/w/api.php?action=opensearch&format=json&search="+ search+"&limit=10&namespace=0&callback=?",
        contentType: "application/json; charset=utf-8",
        async: true,
        dataType : "json" ,
        success: function(data , textStatus, jqXHR){
          console.log(data);

          console.log(data[1].length)
          if(data[1].length == 0)
          {
            $("#result").empty();
            $(".modal").hide();
            $("#result").html("<br><br><br><br><br><br><br><br><br><br><br><br>")
            $("#after").animate({top : '30%'})
            var nores = "<h3><i class='fa fa-frown-o'></i>Sorry  No Results found Please try with another keywords...</h3>" ;
            $("#result").append(nores);
            

          }
          
          else{
          var len = data[1].length;
          //alert(len);
          // alert(data[3][2]) ;
          $("#result").empty();
          $(".modal").hide();
          $("#result").html("<br><br><br><br><br><br><br><br><br><br><br><br>")
          $("#after").animate({top : '30%'})
          for(var i=0 ; i<len ; i++)
            {
              var unique = data[3][i].split("/") ;
              // console.log(unique) ;
              var pass = "preview.php?link=" + unique[4] ;
              // console.log(pass) ;
           ht = "<a href='" + pass + "' target='_blank'><div class='well' style='background-color:#009688; color:white'><h4><b>"+data[1][i]+"</b></h4><h5>"+ data[2][i] + "</h5></div></a>";
          
          $(ht).appendTo("#result").fadeIn("slow");

            }
          
           $(".well").hover(function(){
        $(this).css("background-color", "#00BCD4");
       } , function(){
             $(this).css("background-color", "#009688");
           });
        }

        } //else
       
      })

    }
  }) ;
});