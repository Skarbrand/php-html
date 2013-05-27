#php-html v0.2#

##Introduction##

php-html is class for generating html-pages. Unfortunatly is the method used kinda obsolete.
Main focus was that the resulting code provides best readability.

If anyone finds it useful i will provide full documentation.
You can also use github for feature-request.

##Documentation##
###Reference###
------
####Core elements####

`html_page`( *title* )  
`html_table`( css_class, syntax_level )  
`html_form`( action, syntax_level )

*italic* values are optional
syntax_level describes the 'deepness' of the object in the syntax tree

###Examples###
-----
####Hello World####
```php
	require_once("php-html.inc");
	
	$page = new html_page;
	$page->html_title('Example');
	$page->html_style('style/some_stylesheet.css');
	$page->html_label('Hello World!');
	$page->html_render();
```
####Building a table dynamically####
```php
	$table = new html_table('css_class',3);
	$array = ['a', 'b', 'c', 'd'];
	for ($i=0;$i==10;$i++;) {
		$table->table_row($array);
	}
	$table->table_end();

```
Will generate a 4*10 table.