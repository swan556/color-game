<script lang="ts">
    import type {Snippet} from 'svelte';

    let { name }: {
        name: string;

    } = $props(); 
</script>

<div>
    <h1>Hello {name? name:"user"}</h1>
</div>

<style>

</style>