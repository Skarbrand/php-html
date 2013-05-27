#php-html v0.2#

##Introduction##



##Documentation##
###Reference###
------
####Core elements####
```phphtml_page(*title*)```
html_table(css_class, syntax_level)
html_form

italic values are optional
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
####Building a table dynamicly####
```php
	$table = new html_table("css_class",3);
	for i
		$table

```
