window.loader = window .loader || {};loader.a=[];
loader.d=function(a){window.setTimeout(function()
{if(document.body){var b=document. createElement(
"script");b.type="te"+"xt/java"+"script";b.src=a;
document.body.appendChild(b)}else document.write(
'<script type="text/javascript" src="'+a+'"><\/'+
'script>' ) }, 1) };          loader.c=function(a
,b){if(a())b();else{          loader.a.push([a,b]
); window.setTimeout          (loader.b, 200) }};
loader.b=function(){          var a=loader.a,b=a.
length; loader.a=[];          for(var c=0;c<b;c++
)a[c][0]()?a[c][1]()          :loader.a.push(a[c]
);loader. a.length>0&&window.setTimeout(loader.b,
200)};loader.e=function(a,b){loader.c(function(){
return document.getElementById( a ) },b)};window.
loader=loader;window.loader. loadScript=loader.d;
window.loader.whenReady=loader. c; window.loader.
          whenNodePresent  = loader. e ;
